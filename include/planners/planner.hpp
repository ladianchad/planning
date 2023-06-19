#ifndef PLANNERS__PLANNER_HPP_
#define PLANNERS__PLANNER_HPP_s

#include <memory>
#include "planners/general.hpp"

namespace planners
{

template<class T, class Map = int *>
class Planner
{
public:
  using SharedPtr = std::shared_ptr<Planner>;

  virtual planners::general::Path<T> getPath(
    const typename planners::general::Node<T>::SharedPtr start,
    const typename planners::general::Node<T>::SharedPtr end
  ) = 0;

  virtual void update() {};
};

} // namespace planner
#endif // PLANNERS__PLANNER_HPP_