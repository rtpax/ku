#include "ku.hh"
#include <vector>
#include <chrono>
#include <algorithm>
#include <stdexcept>

std::mt19937 ku::rng = std::mt19937(
  std::chrono::high_resolution_clock::now().time_since_epoch().count()
);

static int remove_O1(std::vector<int> arg, int index) {
  if(index < 0 || index >= arg.size())
    throw std::logic_error("remove_O1: index not in range");
  std::swap(arg.back(), arg[index]);
  int ret = arg.back();
  arg.pop_back();
  return ret;
}

template <class T, class Rng>
static T dist(Rng rng, T min, T max) {
  std::uniform_int_distribution<T> d(min,max);
  return d(rng);
}

void ku::gen() {
  /*first col, randomly ordered*/{
    std::vector<int> col1;
    for(int i = 1; i <= _dim; ++i)
      col1.push_back(i);
    for(int i = 0; i < _dim; ++i) {
      std::swap(col1[i], col1[dist(rng, i+1, _dim-1)]);
    }
    for(int i = 0; i < _dim; ++i)
      _solution[i][0] = col1[i];
  }

  /*second col, follow what you cover, leave room*/{
    std::vector<int> unplaced;
    std::vector<int> uncovered;
    for(int i = 1; i <= _dim; ++i) {
      unplaced.push_back(i);
      uncovered.push_back(i);
    }
    while(!unplaced.empty()) {
      int val = remove_O1(unplaced, dist(rng,0,unplaced.size()-1));
      int loc = -1;
      for(int i = 0; i < _dim; ++i) {

      }
    }
  }

  /*third col, n! permutations per quadrant*/{

  }

  /*first row, randomize what remains*/{

  }

  /*second row, follow what you cover, leave room*/{

  }

  /*third row, n! permutations per quadrant*/{

  }
}

void ku::set(int row, int col, int val) {
  if(!(in_range(row) && in_range(col) && in_range(val - 1))) {
    throw std::logic_error("ku::set argument out of range");
  }
  if(is_preset(row,col)) {
    throw std::logic_error("ku::set cannot modify preset values");
  }

  _grid[row][col] = val;

  auto git = _grid.begin();
  auto sit = _solution.begin();
  bool won = true;
  for(int i = 0; i < _dim * _dim; ++i) {
    if(*git != *sit) {
      won = false;
      break;
    }
  }
  _won = won;
  if(won && (git != _grid.end() || sit != _solution.end())) {
    throw std::logic_error("size of grid is incorrect");
  }
}

int ku::get(int row, int col) {
  if(!(in_range(row) && in_range(col))) {
    throw std::logic_error("ku::get argument out of range");
  }

  return _grid[row][col];
}

bool ku::in_range(int arg) {
  return arg >= 0 && arg < _dim;
}

bool ku::is_preset(int row, int col) {
  return _preset[row][col];
}
