struct segment_tree_node;

segment_tree_node * create_segment_tree(int begin, int end, long long s[]);//包含begin和end元素
//s数组储存着要放入线段树中的数据

int push_delay(segment_tree_node * operated_node);

long long search(int begin, int end, segment_tree_node * operated_node);

int update_multiply(int begin, int end, long long mul, segment_tree_node * operated_node);

int update_plus(int begin, int end, long long plus, segment_tree_node * operated_node);

void modify_mod(long long t);

//为什么没注释!自己都看不懂了!

void free_segment_tree(segment_tree_node *operated_node);