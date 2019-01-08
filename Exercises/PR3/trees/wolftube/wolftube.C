# include <cassert>
# include <cmath>
# include <cstdio>
# include <iostream>
# include <iomanip>
# include <vector>
# include <tuple>

# define NUM_CHILDREN 4

using namespace std;

using Pos = uint64_t;

using Counter = tuple<tuple<uint64_t, uint64_t>, uint64_t>;

using Key = tuple<uint64_t, Pos>;

void build_prefix_counter(vector<Key> & level_tree,
			  vector<Counter> & prefix_counter,
			  Pos curr, Pos parent)
{
  if (curr >= level_tree.size())
    return;
  
  // parent-child
  auto pc = make_tuple(get<0>(level_tree[parent]), get<0>(level_tree[curr]));
  auto counter = make_tuple(pc, 0);
  prefix_counter.push_back(counter);
  get<1>(level_tree[curr]) = prefix_counter.size() - 1;

  for (Pos i = 1; i <= NUM_CHILDREN; ++i)
    {
      Pos p = curr * NUM_CHILDREN + i;
      build_prefix_counter(level_tree, prefix_counter, p, curr);
    }
}

int main()
{
  uint64_t n;
  cin >> n;

  vector<Key> level_tree;

  for (uint64_t i = 0; i < n; ++i)
    {
      uint64_t k;
      cin >> k;
      level_tree.push_back(make_tuple(k, 0));
    }

  vector<Counter> prefix_counter;

  build_prefix_counter(level_tree, prefix_counter, 0, 0);

  uint64_t total = n * n;

  for (uint64_t i = 0; i < total; ++i)
    {
      uint64_t k;
      cin >> k;

      for (auto & item : prefix_counter)
	{
	  ++get<1>(item);
	  
	  if (get<1>(get<0>(item)) == k)
	    break;
	}
    }
  
  for (Pos i = 1; i < level_tree.size(); ++i)
    {
      const Key & item = level_tree[i];
      Counter c = prefix_counter[get<1>(item)];

      double p = double(get<1>(c)) / double(total);
      printf("(%ld %ld) %.2lf\n",get<0>(get<0>(c)), get<1>(get<0>(c)), p);
    }
  
  return 0;
}
