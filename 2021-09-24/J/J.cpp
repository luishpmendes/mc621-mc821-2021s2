#include <iostream>
#include <string>
#include <vector>

void dfs_visit (const std::vector<std::string> & adj,
                unsigned u,
                unsigned v,
                std::vector<bool> & visited) {
    for (unsigned w = 0; w < adj.size(); w++) {
        if (adj[v][w] == '1') {
            if (adj[w][u] == '1') {
                std::cout << u + 1 << ' ' << v + 1 << ' ' << w + 1 << std::endl;
                exit(0);
            }
            if (!visited[w]) {
                dfs_visit(adj, v, w, visited);
            }
        }
    }

    visited[v] = true;
}

void dfs (const std::vector<std::string> & adj, std::vector<bool> & visited) {
    for (unsigned u = 0; u < adj.size(); u++) {
        if (!visited[u]) {
            dfs_visit(adj, u, u, visited);
        }
    }
}

int main () {
    unsigned n, i;

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> n;

    std::vector<std::string> adj (n);
    std::vector<bool> visited (n, false);

    for (i = 0; i < n; i++) {
        std::cin >> adj[i];
    }

    dfs(adj, visited);

    std::cout << -1 << std::endl;

    return 0;
}

