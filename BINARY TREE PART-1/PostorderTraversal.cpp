#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

vector < int > postOrderTrav(node * cur) {

  vector < int > postOrder;
  if (cur == NULL) return postOrder;

  stack < node * > st;
  while (cur != NULL || !st.empty()) {

    if (cur != NULL) {
      st.push(cur);
      cur = cur -> left;
    } else {
      node * temp = st.top() -> right;
      if (temp == NULL) {
        temp = st.top();
        st.pop();
        postOrder.push_back(temp -> data);
        while (!st.empty() && temp == st.top() -> right) {
          temp = st.top();
          st.pop();
          postOrder.push_back(temp -> data);
        }
      } else cur = temp;
    }
  }
  return postOrder;

}

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

int main() {

  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> right = newNode(3);
  root -> left -> left = newNode(4);
  root -> left -> right = newNode(5);
  root -> left -> right -> left = newNode(8);
  root -> right -> left = newNode(6);
  root -> right -> right = newNode(7);
  root -> right -> right -> left = newNode(9);
  root -> right -> right -> right = newNode(10);

  vector < int > postOrder;
  postOrder = postOrderTrav(root);

  cout << "The postOrder Traversal is : ";
  for (int i = 0; i < postOrder.size(); i++) {
    cout << postOrder[i] << " ";
  }
  return 0;
}