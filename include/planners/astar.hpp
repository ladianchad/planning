#ifndef PLANNERS__A_STAR_HPP_
#define PLANNERS__A_STAR_HPP_

#include "planners/general.hpp"
#include "planners/planner.hpp"

namespace planners
{

namespace astar
{

template<class T>
class Node : public planners::general::Node<T>
{
public:
  using SharedPtr = std::shared_ptr<Node>;

  double getHuristricCost(const Node::SharedPtr node);
};

template<class T>
class AStar : public Planner<T>
{
public:

  planners::general::Path<T> getPath(
    const typename planners::general::Node<T>::SharedPtr start,
    const typename planners::general::Node<T>::SharedPtr end
  ) override
  {
    
  }

private:
};


} // namespace astar
} // namespace planners

#endif // PLANNERS__A_STAR_HPP_