#include "planners/general.hpp"

#include <vector>
#include <iostream>

int main(int, char const *[])
{
  std::vector<planners::general::Node<int>::SharedPtr> nodes;

  for (size_t i = 0; i < 10; i++)
  {
    nodes.push_back(std::make_shared<planners::general::Node<int>>(i));
  }

  for (size_t i = 1; i < 10; i++)
  {
    nodes[i]->addConnectedNode(nodes[i-1], i, true);
  }

  for (const auto & node : nodes)
  {
    const auto connected_nodes = node->getConnectedCosts();
    std::cout<<"=========++ node "<<node->getKey()<<" ++========="<<std::endl;
    for (auto c = connected_nodes->begin(); c != connected_nodes->end(); c++)
    {
      std::cout<<"neighbor"<<std::endl;
      std::cout<<"id : "<<c->first->getKey()<<std::endl;
      std::cout<<"cost : "<<c->second<<std::endl;
    }
  }
  
  
  return 0;
}
