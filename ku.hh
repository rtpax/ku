#include <boost/multi_array.hpp>
#include <random>

class ku {
public:
  ku() : ku(3) {}
  ku(int root) :
    _won(false),
    _root(root),
    _dim(root * root),
    _grid(boost::extents[_dim][_dim]),
    _solution(boost::extents[_dim][_dim]),
    _preset(boost::extents[_dim][_dim]) {}
  ku(const ku& copy) :
    _won(copy._won),
    _root(copy._root),
    _dim(copy._dim),
    _grid(copy._grid),
    _solution(copy._solution),
    _preset(copy._preset) {}
  void gen();
  void set(int row, int col, int val);
  int get(int row, int col);
  bool is_preset(int row, int col);
private:
  bool in_range(int arg);

  static std::mt19937 rng;

  bool _won;
  int _root;
  int _dim;
  boost::multi_array<int,2> _grid;
  boost::multi_array<int,2> _solution;
  boost::multi_array<bool,2> _preset;
};
