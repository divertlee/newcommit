
//37.������
//class Solution {
//public:
//    bool recall(vector<vector<char>>& board)
//    {
//        for (int row = 0; row < board.size(); row++)//������
//        {
//            for (int col = 0; col < board[row].size(); col++)
//            {
//                if (board[row][col] == '.')
//                {
//                    for (char k = '1'; k <= '9'; k++)
//                    {
//                        if (istrue(board, row, col, k))
//                        {
//                            board[row][col] = k;
//                            if (recall(board))return true;//���ݣ����ǰ�涼returntrue����ǰ�涼��Ψһ�Һ��ʵ�λ��
//                            board[row][col] = '.';
//                        }
//
//                    }
//                    return false;
//                }
//                else
//                {
//                    continue;
//                }
//
//            }
//        }
//        return true;
//    }
//
//    bool istrue(vector<vector<char>>& board, int row, int col, char val)
//    {
//        //�����
//        for (int j = 0; j < 9; j++)//0-8
//        {
//            if (board[row][j] == val)
//            {
//                return false;
//            }
//        }
//        //�����
//        for (int i = 0; i < 9; i++)
//        {
//            if (board[i][col] == val)
//            {
//                return false;
//            }
//        }
//        //������ָ�
//        int startrow = (row / 3) * 3;//��������һ�����ָ�
//        int startcol = (col / 3) * 3;
//        for (int i = startrow; i < startrow + 3; i++)
//        {
//            for (int j = startcol; j < startcol + 3; j++)
//            {
//                if (board[i][j] == val)
//                {
//                    return false;
//                }
//            }
//        }
//        return true;
//    }
//    void solveSudoku(vector<vector<char>>& board) {
//        recall(board);
//    }
//};