#ifndef PLANNERS__GENERAL_HPP_
#define PLANNERS__GENERAL_HPP_

#include <memory>
#include <map>
#include <vector>

namespace planners
{

namespace general
{

template<typename T>
class NodeCost;

template<typename T>
class Node : public std::enable_shared_from_this<Node<T>>
{
public:
  using SharedPtr = std::shared_ptr<Node<T>>;

  Node(const T key = T())
  : key_(key)
  {
    this->connected_nodes_ = std::make_shared<NodeCost<T>>();
  }

  T getKey()
  {
    return this->key_;
  }

  void addConnectedNode(const typename Node<T>::SharedPtr node, double cost, bool by_direction = false)
  {
    this->connected_nodes_->addCost(node, cost);
    if(by_direction){
      node->addConnectedNode(this->shared_from_this(), cost, false);
    }
  }

  void removeConnectedNode(const typename Node<T>::SharedPtr node)
  {
    this->connected_nodes_->removeCost(node);
  }

  bool checkConnectedNodeExist(const typename Node<T>::SharedPtr node)
  {
    return this->connected_nodes_->checkCostExist(node);
  }

  const std::shared_ptr<NodeCost<T>> getConnectedCosts()
  {
    return this->connected_nodes_;
  }

protected:
  const T key_;
  std::shared_ptr<NodeCost<T>> connected_nodes_;
};

template<typename T>
class NodeCost
{
public:
  using SharedPtr = std::shared_ptr<NodeCost>;

  void addCost(const typename Node<T>::SharedPtr node, const double cost)
  {
    this->cost_map_[node] = cost;
  }

  void updateCost(const typename Node<T>::SharedPtr node, const double cost)
  {
    this->cost_map_[node] = cost;
  }

  void removeCost(const typename Node<T>::SharedPtr node)
  {
    this->cost_map_.erase(node);
  }

  double getCost(const typename Node<T>::SharedPtr node)
  {
    return this->cost_map_[node];
  }

  bool checkCostExist(const typename Node<T>::SharedPtr node)
  {
    return this->cost_map_.find(node) != this->cost_map_.end();
  }

  const typename std::map<typename Node<T>::SharedPtr, double>::iterator begin()
  {
    return this->cost_map_.begin();
  }

  const typename std::map<typename Node<T>::SharedPtr, double>::iterator end()
  {
    return this->cost_map_.end();
  }

protected:
  std::map<typename Node<T>::SharedPtr, double> cost_map_;
};

template<typename T>
using Path = std::vector<typename Node<T>::SharedPtr>;

} // namespace general
} // namespace planners

#endif // PLANNERS__GENERAL_HPP_