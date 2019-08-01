#ifndef INCLUDE_CCSPEC_CORE_EXAMPLE_GROUP_MANAGER_HPP_
#define INCLUDE_CCSPEC_CORE_EXAMPLE_GROUP_MANAGER_HPP_

#include "ccspec/core/example_group.h"
#include <initializer_list>
#include <map>
#include <vector>
#include <random>

namespace ccspec {
namespace core {
    class ExampleGroupManager;

    class SpecTag
    {
    public:
      SpecTag(){

      }
      SpecTag(const std::initializer_list<const char*>& tags){
        for(auto& item : tags) {
          m_all_tags.push_back(item);
        }
      }
      ~SpecTag(){

      }
    public:
      ExampleGroup* describe(std::string desc,
                             std::function<void()> spec);

      bool is_match_tag(const std::string& _str){
        if(_str.empty()) return true;

        for(auto& item : m_all_tags ){
          if(item == _str){
            return true;
          }
        }   
        return false;
      }
    private:
      std::list<std::string> m_all_tags;
    };
    class ExampleGroupManager {
    private:
      ExampleGroupManager(){

      }
    public:
      ~ExampleGroupManager(){

      }
      static ExampleGroupManager& getInstance();

    public:
      typedef SpecTag TagCreater(const std::initializer_list<const char*>& tags);
    public:
      void add_top_example_group(ExampleGroup* group){
        if(group == nullptr) return;
        auto iterator = m_groups.find(group);
        if(iterator == m_groups.end()){
          SpecTag tag;
          m_groups.insert(std::make_pair(group, tag));          
        }
      }

      void set_example_group_tag(ExampleGroup* group, const SpecTag& tag){
         if(!is_top_group(group)) return;
         auto& origin_tag = m_groups[group];
         origin_tag = tag;
      }
      bool is_top_group(ExampleGroup* group){
        auto iterator = m_groups.find(group);
        if(iterator != m_groups.end()){
          return true;
        } 
        return false;
      }      
      std::vector<ExampleGroup*> filter_groups(const std::string& _tag,
                                             bool random = true){
        std::vector<ExampleGroup*> ret;
        for(auto& [group, spec_tag] : m_groups){
          if(spec_tag.is_match_tag(_tag)){
            ret.push_back(group);
          }
        }                        
        if(true){

          std::random_device rd;
          std::mt19937 g(rd());
          std::shuffle(ret.begin(), ret.end(),g);
        }                    
        return ret;
      }
    private:
      
      std::map<ExampleGroup*, SpecTag> m_groups;
    
    private:
      friend TagCreater tag;
    };

    inline ExampleGroupManager& ExampleGroupManager::getInstance(){
      static ExampleGroupManager m_instance;
      return m_instance;
    }

    inline SpecTag tag(const std::initializer_list<const char*>& tags){
      SpecTag spec_tag(tags);
      return spec_tag;
    }

    inline ExampleGroup* SpecTag::describe(std::string desc,
                                    std::function<void()> spec){

      auto example_group = ccspec::core::describe(desc, spec);
      auto& group_manager = ExampleGroupManager::getInstance();
      if(!group_manager.is_top_group(example_group)){
        return example_group;
      }
      group_manager.set_example_group_tag(example_group, *this);
      return example_group;
    }

  } ///namespace core
}///namesapce ccspec



#endif ///INCLUDE_CCSPEC_CORE_EXAMPLE_GROUP_MANAGER_HPP_
