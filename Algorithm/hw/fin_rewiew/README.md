# 演算法期末複習

## [1128 . Last Larger Integers](https://oj.nctu.edu.tw/problems/1128/)
### 回朔（？） | 我看這是通靈

## [1129 . Split Connected Components](https://oj.nctu.edu.tw/problems/1129/)
### connected component | bfs | 反過來做

## [1130 . Shortest Manhattan Walk](https://oj.nctu.edu.tw/problems/1130/)
### bfs | 移動迷宮
- `|=` 沒有比較快
- 迴圈也沒有比較慢

## [1131 . Shortest Closed Walk](https://oj.nctu.edu.tw/problems/1131/)
### 原味 dijkstra | priority queue
- `bool operator<(const struct node_& r)const`
- 不難啦...

## [1132 . Second Largest Strongly Connected Component](https://oj.nctu.edu.tw/problems/1132/)
### SCC | DFS
- 不要亂開全域變數誒
- time 是保留字
- dfs:
    - time ++ -> u.d
    - u.color grey
    - for -> if 沒有 visit(white) 則記 pi、遞迴
    - u.color black
    - time ++ -> u.f
