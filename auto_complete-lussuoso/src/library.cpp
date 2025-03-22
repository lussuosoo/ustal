#include "library.hpp"
#include <iostream>

namespace template_library {

    void AutoComplete::insert(const std::string& word) {
        Node* current = root;
        for (char ch : word) {
            if (current->children.count(ch) == 0) {
                current->children[ch] = new Node();
            }
            current = current->children[ch];
        }
        current->is_end = true;
    }

    std::vector<std::string> AutoComplete::suggest(const std::string& prefix) {
        std::vector<std::string> result;
        Node* current = root;

        
        for (char ch : prefix) {
            if (current->children.count(ch) == 0) {
                return result; 
            }
            current = current->children[ch];
        }

        std::string path = prefix;
        dfs(current, path, result);
        return result;
    }

    void AutoComplete::dfs(Node* node, std::string& path, std::vector<std::string>& result) {
        if (node->is_end) {
            result.push_back(path); 
        }

        for (auto& pair : node->children) {
            path.push_back(pair.first); 
            dfs(pair.second, path, result);
            path.pop_back(); 
        }
    }
}