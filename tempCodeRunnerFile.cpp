for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            char value = 'A'+row+col-1;
            std::cout <<  value;
        }
        cout<<endl;
    }