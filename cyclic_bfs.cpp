#include <iostream>
#include <queue>

void bfs(int matrix[7][7], char vertices[7], int start) {
  bool visited[7] = {false};
  int parent[7];
  for (int i = 0; i < 7; i++) {
    parent[i] = -1;
  }

  std::queue<int> q;
  q.push(start);
  visited[start] = true;

  while (!q.empty()) {
    int current = q.front();
    q.pop();

    for (int i = 0; i < 7; i++) {
      if (matrix[current][i] == 1) {
        if (!visited[i]) {
          visited[i] = true;
          parent[i] = current;
          q.push(i);
        } 
        else if (i != parent[current]) {
          std::cout << "Cycle found: ";
          std::cout << vertices[current] << " ";
          int temp = current;
          while (temp != i) {
            temp = parent[temp];
            std::cout << vertices[temp] << " ";
          }
          std::cout << vertices[i] << std::endl;
        }
      }
    }
  }
}

void findAllCycles(int matrix[7][7], char vertices[7]) {
  bool globalVisited[7] = {false};

  for (int i = 0; i < 7; i++) {
    if (!globalVisited[i]) {
      bfs(matrix, vertices, i);
      for (int j = 0; j < 7; j++) {
        globalVisited[j] = true;
      }
    }
  }
}

int main() {
  char vertices[7] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
  int matrix[7][7] = {
    {0, 0, 1, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 0},
    {1, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0}
  };

  std::cout << "Cycles in the graph:\n";
  findAllCycles(matrix, vertices);

  return 0;
}
