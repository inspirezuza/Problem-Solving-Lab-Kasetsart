 (q--) {
        int r, c, a, b;
        cout << "adsf";
        vector<vector<int>> visited(n, vector<int>(n, 0));
        cin >> r >> c >> a >> b;
        dfsMaze(r, c, a, b, visited, maze, 1);
    }