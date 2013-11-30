#include <iostream>
#include <vector>
#include <set>
#include <fstream>

#define DEBUG 0

using namespace std;

struct Cell {
  int n;
  set<int> p;
  Cell (int n_, set<int> p_) : n(n_), p(p_) {}
};

typedef vector< vector<Cell> > State;

vector<pair<int,int> > rowDeleter(State &cells, int i, int val) {
  vector< pair<int,int> > result;
  for(int y = 0; y < 9; y++) {
    set<int>::iterator f = cells[i][y].p.find(val);
    if (f != cells[i][y].p.end()) {
      result.push_back(make_pair(i, y));
      cells[i][y].p.erase(f);
    }
  }
  return result;
}

vector<pair<int,int> > colDeleter(State &cells, int j, int val) {
  vector< pair<int,int> > result;
  for(int y = 0; y < 9; y++) {
    set<int>::iterator f = cells[y][j].p.find(val);
    if (f != cells[y][j].p.end()) {
      result.push_back(make_pair(y, j));
      cells[y][j].p.erase(f);
    }
  }
  return result;
}

vector<pair<int,int> > boxDeleter(State &cells, int i, int j, int val) {
  if (i < 3) i = 0;
  else if (i < 6) i = 3;
  else i = 6;
  if (j < 3) j = 0;
  else if (j < 6) j = 3;
  else j = 6;
  vector< pair<int,int> > result;
  for(int x = i; x < i+3; x++) {
    for(int y = j; y < j+3; y++) {
      set<int>::iterator f = cells[x][y].p.find(val);
      if (f != cells[x][y].p.end()) {
        result.push_back(make_pair(x, y));
        cells[x][y].p.erase(f);
      }
    }
  }
  return result;
}

void doDeductions (State& cells) {
  while (true) {
    bool deduction = false;
    for(int i = 0; i < 9; i++) {
      if (deduction) break;
      for(int j = 0; j < 9; j++) {
        if (cells[i][j].n == 0 && cells[i][j].p.size() == 1) {
          int val = *cells[i][j].p.begin();
          cells[i][j].n = val;
          rowDeleter(cells, i, val);
          colDeleter(cells, j, val);
          boxDeleter(cells, i, j, val);
          deduction = true;
          break;
        }
      }
    }
    if (!deduction) break;
  }
}

bool contradiction (State const& cells) {
  for(int i = 0; i < 9; i++) {
    for(int j = 0; j < 9; j++) {
      if (cells[i][j].n == 0 && cells[i][j].p.size() == 0)
        return true;
    }
  }
  return false;
}

void printSudoku(State& cells) {
  for(int i = 0; i < 9; i++) {
    for(int j = 0; j < 9; j++) {
      cout << cells[i][j].n;
    }
    cout << endl;
  }
  cout << endl;
}

void updateCells (State& cells, int i, int j, int val) {
  rowDeleter(cells, i, val);
  colDeleter(cells, j, val);
  boxDeleter(cells, i, j, val);
}

int main ()
{
  // Sudoku Solver
  ifstream fin("sudoku.txt");
  int ans = 0;
  for(int t = 0; t < 50; t++) {
    string line;
    getline(fin, line);
    if (line == "") getline(fin, line);
    vector<string> board(9);
    for(int j = 0; j < 9; j++)
      fin >> board[j];
    set<int> temp;
    for(int j = 1; j <= 9; j++)
      temp.insert(j);
    State cells;
    for(int i = 0; i < 9; i++) {
      vector<Cell> tempRow;
      for(int j = 0; j < 9; j++) {
        tempRow.push_back(Cell(board[i][j]-'0', temp));
      }
      cells.push_back(tempRow);
    }

    // Update all cells
    for(int i = 0; i < 9; i++) {
      for(int j = 0; j < 9; j++) {
        if (cells[i][j].n != 0) {
          updateCells(cells, i, j, cells[i][j].n);
        }
      }
    }

    doDeductions(cells);
    vector<State> Q;
    Q.push_back(cells);
    int numZeros = 0;
    for(int i = 0; i < 9; i++) {
      for(int j = 0; j < 9; j++) {
        if (cells[i][j].n == 0)
          numZeros++;
      }
    }
    State ansGrid;
    if (numZeros == 0)
      ansGrid = cells;
    for(int k = 0; k < numZeros; k++) {
      int size = Q.size();
      bool done = false;
      for(int i = 0; i < size; i++) {
        // find first 0 entry
        bool found = false;
        for(int x = 0; x < 9; x++) {
          if (found) break;
          for(int y = 0; y < 9; y++) {
            if (found) break;
            if (Q[i][x][y].n == 0) {
              found = true;
              for(auto& val : Q[i][x][y].p) {
                State temp(Q[i].begin(), Q[i].end());
                temp[x][y].n = val;
                updateCells(temp, x, y, val);
                doDeductions(temp);
                if (!contradiction(temp)) {
                  Q.push_back(temp);
                }
              }
              break;
            }
          }
        }
        if (!found) {
          ansGrid = Q[i];
          done = true;
          break;
        }
      }
      if (done) break;
      Q.erase(Q.begin(), Q.begin()+size);
    }

    cout << "Grid #" << t+1 << endl;
    printSudoku(ansGrid);
    ans += ansGrid[0][0].n * 100 + ansGrid[0][1].n * 10 + ansGrid[0][2].n;
    cout << endl;
  }
  cout << "Answer: " << ans << endl;
  fin.close();
}
