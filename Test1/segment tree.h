struct node;

node * create_segment_tree(int begin, int end, long long s[]);

int push_delay(node * operated_node);

long long search(int begin, int end, node * operated_node);

int update_multiply(int begin, int end, long long mul, node * operated_node);

int update_plus(int begin, int end, long long plus, node * operated_node);
