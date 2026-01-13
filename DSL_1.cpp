#include <iostream>
using namespace std;

int main()
{
    int A[2][2], B[2][2], R[2][2];
    int choice;

    // Input Matrix A
    cout << "Enter elements of Matrix A (2x2):\n";
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            cin >> A[i][j];

    // Input Matrix B
    cout << "Enter elements of Matrix B (2x2):\n";
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            cin >> B[i][j];

    do
    {
        cout << "\n--- MENU ---\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division (A * inverse of B)\n";
        cout << "5. Transpose\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1: // Addition
                cout << "\nAddition:\n";
                for(int i = 0; i < 2; i++)
                {
                    for(int j = 0; j < 2; j++)
                    {
                        R[i][j] = A[i][j] + B[i][j];
                        cout << R[i][j] << " ";
                    }
                    cout << endl;
                }
                break;

            case 2: // Subtraction
                cout << "\nSubtraction (A - B):\n";
                for(int i = 0; i < 2; i++)
                {
                    for(int j = 0; j < 2; j++)
                    {
                        R[i][j] = A[i][j] - B[i][j];
                        cout << R[i][j] << " ";
                    }
                    cout << endl;
                }
                break;

            case 3: // Multiplication
                cout << "\nMultiplication:\n";
                for(int i = 0; i < 2; i++)
                {
                    for(int j = 0; j < 2; j++)
                    {
                        R[i][j] = 0;
                        for(int k = 0; k < 2; k++)
                            R[i][j] += A[i][k] * B[k][j];

                        cout << R[i][j] << " ";
                    }
                    cout << endl;
                }
                break;

            case 4: // Division (A * inverse of B)
            {
                int det = B[0][0]*B[1][1] - B[0][1]*B[1][0];

                if(det == 0)
                {
                    cout << "Division not possible (determinant is zero).\n";
                    break;
                }

                float invB[2][2];
                invB[0][0] =  B[1][1] / (float)det;
                invB[0][1] = -B[0][1] / (float)det;
                invB[1][0] = -B[1][0] / (float)det;
                invB[1][1] =  B[0][0] / (float)det;

                float result[2][2] = {0};

                cout << "\nDivision Result:\n";
                for(int i = 0; i < 2; i++)
                {
                    for(int j = 0; j < 2; j++)
                    {
                        for(int k = 0; k < 2; k++)
                            result[i][j] += A[i][k] * invB[k][j];

                        cout << result[i][j] << " ";
                    }
                    cout << endl;
                }
                break;
            }

            case 5: // Transpose
                cout << "\nTranspose of Matrix A:\n";
                for(int i = 0; i < 2; i++)
                {
                    for(int j = 0; j < 2; j++)
                        cout << A[j][i] << " ";
                    cout << endl;
                }

                cout << "\nTranspose of Matrix B:\n";
                for(int i = 0; i < 2; i++)
                {
                    for(int j = 0; j < 2; j++)
                        cout << B[j][i] << " ";
                    cout << endl;
                }
                break;

            case 6:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 6);

    return 0;
}

