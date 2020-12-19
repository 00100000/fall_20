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

# 期中考範圍

## [1110. Powers of Complex Numbers](https://oj.nctu.edu.tw/problems/1110/)
### 快速冪運算 | 複數

- template 很戳
- {a, b} 不是 vector
- 取 mod 要讓他變正ㄉ
- pair 在 \<utility\>
- 要一直一直取 mod

## [1111. Inverted Triplets](https://oj.nctu.edu.tw/problems/1111/)
### 逆序數對 | merge sort
- 底部出罷個哭啊XD
- ### long long 啦
- 先砍一半然後分別遞迴 `merge_sort(int st, int ed)` 再合併


## [1112. Lambert W Function](https://oj.nctu.edu.tw/problems/1112/)
### 二分搜 | long double
- long double (`%Lf`)
- 太精細ㄉ先不要
- template 很戳

## [1113. Yet Another Vintage Screen](https://oj.nctu.edu.tw/problems/1113/)
### 二分搜尋

## [1114. Percentiles](https://oj.nctu.edu.tw/problems/1114/)
### Multiset | iterator
- multiset\<int\>::iterator
- 0% 時要注意ㄍ
- 一樣的 key 會放在比較後面

## [1115. Maximum Sum of Subsequences](https://oj.nctu.edu.tw/problems/1115/)
### Segmemt tree | 不要寫太醜ㄛ
- 一個點的 nn 是 0

## [1116. Cost of Subtractions](https://oj.nctu.edu.tw/problems/1116/)
### priority queue

## [1117. Distinct Points](https://oj.nctu.edu.tw/problems/1117/)
### 文式圖

## [1120. Longest Palindromic Subsequence](https://oj.nctu.edu.tw/problems/1120/)
### DP | LCS
- 記憶體不要平方！（兩三個 row）
- 如果這兩個字一樣就左上角ㄉ +1 記下來，不一樣就不要加一

## [1121. Shortest Interval Cover]()
### Binary Search
- 範圍要注意下

## [1122. Knapsack with Volumes]()
### DP | 背包問題
-  volume, weight 二維陣列

# 期中考題

## [1123 . Quiz 1.1 - Exponential Lambert W Function]()
### Binary Search | 換底公式
- `__INT_MAX__` -> 前後各有兩個底線喔
- long double 了解一下

## [1124 . Quiz 1.2 - Range Maximum Query]()
### Segment Tree

## [1125 . Quiz 1.3 - Longest Common Subsequence]()
### LCS

## [1126 . Quiz 1.4 - Activity Selection with Two Spaces]()
### Greedy

## [1127 . Quiz 1.5 - Productivity Programming]()
### DP