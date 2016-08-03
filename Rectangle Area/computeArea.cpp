int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int a, b, c, d;
        if (A >= E)
            a = A;
        else
            a = E;
        if (B >= F)
            b = B;
        else
            b = F;
        if (C >= G)
            c = G;
        else
            c = C;
        if (D >= H)
            d = H;
        else
            d = D;
        if (c>a && d>b)
            return (C-A)*(D-B)+(G-E)*(H-F)-(c-a)*(d-b);
        else
            return (C-A)*(D-B)+(G-E)*(H-F);
    }