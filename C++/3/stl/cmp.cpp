#include <iostream>  
#include <queue>  

using namespace std;  

class Node{  
	int x, y;  
} node;  

class cmp {  
	bool operator()(Node a,Node b){  
		if(a.x==b.x) 
			return a.y>b.y;  
		return a.x>b.x;
	}  
};  

int main() {  

	priority_queue<Node,vector<Node>,cmp>q;  

	for(int i=0;i<10;i++){  
		node.x=i;  
		node.y=10-i/2;  
		q.push(node);     
	}     
	while(!q.empty()){  
		cout<<q.top().x<<' '<<q.top().y<<endl;  
		q.pop();  
	}  
	return 0;  
}  
