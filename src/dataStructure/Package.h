//
// Created by le on 8/11/2022.
//

#ifndef LANGUAGEBASIC_PACKAGE_H
#define LANGUAGEBASIC_PACKAGE_H

#include<iostream>

using namespace std;

class Package {

public:
    static const int MAXN = 1005;
    int v[MAXN];    // 体积
    int w[MAXN];    // 价值
    int f[MAXN][MAXN];  // f[i][j], j体积下前i个物品的最大价值

    void zeroOnePackage()
    {
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++)
            cin >> v[i] >> w[i];

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
            {
                //  当前背包容量装不进第i个物品，则价值等于前i-1个物品
                if(j < v[i])
                    f[i][j] = f[i - 1][j];
                    // 能装，需进行决策是否选择第i个物品
                else
                    f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i]);
            }

        cout << f[n][m] << endl;
    }

};


#endif //LANGUAGEBASIC_PACKAGE_H
