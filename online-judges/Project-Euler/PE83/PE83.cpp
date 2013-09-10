#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

#define MATRIX_SIZE 80

using namespace std;

struct Node {
  int id_;
  int value_;
  vector<int> neighbours_;
  bool visited_;
  int currentValue_;
  Node (int id, int value) {
    this->id_ = id;
    this->value_ = value;
    this->visited_ = false;
    this->currentValue_ = 2147000000;
    //cout << "ID: " << this->id_ << endl;
    //cout << "1: " << this->id_ - 1 << endl;
    //cout << "2: " << this->id_ + 1 << endl;
    //cout << "3: " << this->id_ - MATRIX_SIZE << endl;
    //cout << "4: " << this->id_ + MATRIX_SIZE << endl;
    if (this->id_ % MATRIX_SIZE != 0)
      this->neighbours_.push_back(this->id_ - 1);
    if (this->id_ % (MATRIX_SIZE) != MATRIX_SIZE-1)
      this->neighbours_.push_back(this->id_ + 1);
    if (this->id_ / MATRIX_SIZE != 0)
      this->neighbours_.push_back(this->id_ - MATRIX_SIZE);
    if (this->id_ / MATRIX_SIZE != MATRIX_SIZE-1)
      this->neighbours_.push_back(this->id_ + MATRIX_SIZE);
  }
};

bool op (Node const& A, Node const& B) {
  if (A.currentValue_ != B.currentValue_)
    return A.currentValue_ < B.currentValue_;
  else
    return A.id_ < B.id_;
}


int searchID(vector<Node>& nodes, int id) {
  for (int i = 0; i < MATRIX_SIZE * MATRIX_SIZE; i++) {
    if (nodes[i].id_ == id)
      return i;
  }
}

int main ()
{
  ifstream fin("matrix.txt");
  int num;
  vector<Node> nodes;
  for(int i = 0; i < MATRIX_SIZE; i++) {
    for(int j = 0; j < MATRIX_SIZE; j++) {
      fin >> num;
      if (i == 0 && j == 0) {
        Node first(0, num);
        first.currentValue_ = num;
        nodes.push_back(first);
      }
      else {
        nodes.push_back(Node(i*MATRIX_SIZE + j, num));
      }
    }
  }
  sort(nodes.begin(), nodes.end(), op);
  while (true){
    int curr = 0;
    for (; curr < MATRIX_SIZE * MATRIX_SIZE; curr++) {
      if (!nodes[curr].visited_)
        break;
    }
    Node top = nodes[curr];
    //cout << "TOP: " << top.id_ << endl;
    //cout << "currentValue: " << top.currentValue_ << endl;
    if (top.id_ == MATRIX_SIZE * MATRIX_SIZE - 1) {
      cout << top.currentValue_ << endl;
      break;
    }
    nodes[curr].visited_ = true;
    for(int i = 0; i < int(top.neighbours_.size()); i++) {
      int newIndex = searchID(nodes, top.neighbours_[i]);
      Node currentNode = nodes[newIndex];
      //cout << "neighbour: " << currentNode.id_ << endl;
      if (!currentNode.visited_) {
        int V = top.currentValue_+currentNode.value_;
        if (V < currentNode.currentValue_) {
          nodes[newIndex].currentValue_ = V;
        }
      }
    }
    sort(nodes.begin(), nodes.end(), op);
    curr++;
  }
}
