#include <iostream>

void printCycle(int path[], int pathLength, int startIdx, char vertices[]) {
  for (int i = startIdx; i < pathLength; i++) {
    std::cout << vertices[path[i]] << " ";
  }
  std::cout << vertices[path[startIdx]] << std::endl;
}

void dfs(int matrix[7][7], char vertices[7], bool visited[], bool onPath[], int path[], int pathLength, int current, bool &cycleFound) {
  visited[current] = true;
  onPath[current] = true;
  path[pathLength] = current;
  pathLength++;

  for (int i = 0; i < 7; i++) {
    if (matrix[current][i] == 1) {
      if (onPath[i]) {
        std::cout << "Cycle found: ";
        int cycleStart = 0;
        for (int j = 0; j < pathLength; j++) {
          if (path[j] == i) {
            cycleStart = j;
            break;
          }
        }
        printCycle(path, pathLength, cycleStart, vertices);
        cycleFound = true;
      } else if (!visited[i]) {
        dfs(matrix, vertices, visited, onPath, path, pathLength, i, cycleFound);
      }
    }
  }

  onPath[current] = false;
}

void findAllCycles(int matrix[7][7], char vertices[7]) {
  bool visited[7] = {false};
  bool onPath[7] = {false};
  int path[14] = {0};
  bool cycleFound = false;

  for (int i = 0; i < 7; i++) {
    if (!visited[i]) {
      dfs(matrix, vertices, visited, onPath, path, 0, i, cycleFound);
    }
  }

  if (cycleFound) {
    std::cout << "Yes, cycle found!" << std::endl;
  } else {
    std::cout << "No cycle there!" << std::endl;
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
