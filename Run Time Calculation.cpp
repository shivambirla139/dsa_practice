    auto start = chrono::high_resolution_clock::now();


    Solution sol = Solution();
    sol.solvePuzzle(board);

    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "Time taken: " << duration.count() << " ms\n";
