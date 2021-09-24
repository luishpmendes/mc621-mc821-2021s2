#include <list>
#include <iostream>
#include <vector>

#define WHITE 0
#define GRAY  1
#define BLACK 2

void dfs_visit (const std::vector<std::list<unsigned>> & adj,
                unsigned u,
                unsigned & time,
                std::vector<unsigned> & color,
                std::vector<unsigned> & pi,
                std::vector<unsigned> & d,
                std::vector<unsigned> & f,
                unsigned k,
                unsigned & first,
                unsigned & last) {
    time++;
    d[u] = time;
    color[u] = GRAY;

    for (const unsigned & v : adj[u]) {
        if (color[v] == WHITE) {
            pi[v] = u;
            dfs_visit(adj, v, time, color, pi, d, f, k, first, last);
        } else {
            if (d[u] - d[v] >= k) {
                first = v;
                last = u;
            }
        }

        if (first < adj.size()) {
            break;
        }
    }

    color[u] = BLACK;
    time++;
    f[u] = time;
}

void dfs (const std::vector<std::list<unsigned>> & adj,
          std::vector<unsigned> & pi,
          std::vector<unsigned> & d,
          std::vector<unsigned> & f,
          unsigned k,
          unsigned & first,
          unsigned & last) {
    std::vector<unsigned> color (adj.size(), WHITE);
    unsigned time = 0;
    first = last = adj.size();

    pi.clear();
    pi.resize(adj.size(), adj.size());
    d.clear();
    d.resize(adj.size(), std::numeric_limits<unsigned>::max());
    f.clear();
    f.resize(adj.size(), std::numeric_limits<unsigned>::max());

    for (unsigned u = 0; u < adj.size() && first >= adj.size(); u++) {
        if (color[u] == WHITE) {
            dfs_visit(adj, u, time, color, pi, d, f, k, first, last);
        }
    }
}

int main () {
    unsigned n, m, k, a, b, i, first, last;
    std::vector<std::list<unsigned>> adj;
    std::vector<unsigned> pi, d, f, c;

    while (std::cin >> n >> m >> k) {
        adj.clear();
        adj.resize(n);

        for (i = 0; i < m; i++) {
            std::cin >> a >> b;
            a--;
            b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        dfs(adj, pi, d, f, k, first, last);

        c.clear();

        while (last != first) {
            c.push_back(last);
            last = pi[last];
        }

        c.push_back(first);

        std::cout << c.size() << std::endl;

        for (i = 0; i < c.size() - 1; i++) {
            std::cout << c[i] + 1 << ' ';
        }

        std::cout << c.back() + 1 << std::endl;

    }

    return 0;
}

