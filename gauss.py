import os, sys
import numpy as np
def clear():os.system('clear' if 'linux' in sys.platform.lower() else 'cls')

class gjd_ordo_3x4():

    def __init__(self):

        self.arr = np.array([ #--> Contoh 1 Valid
            [2,  0,  6, 40],
            [0,  4, -1, 10],
            [2, -1,  2, 12]], dtype=float)
        
        # self.arr = np.array([ #--> Contoh 2 Valid
        #     [-5, 0,  7, -32],
        #     [ 0, 3, -6,  48],
        #     [ 2, 1,  4, -24]], dtype=float)
        
        # self.arr = np.array([ #--> Contoh 3 Tidak Valid
        #     [ 3, -3,  2, -17],
        #     [ 4,  7, -4,  21],
        #     [-4,  6, -5,  25]], dtype=float)

        self.__exec__()

    def __exec__(self):
        m,n = self.arr.shape
        np.set_printoptions(precision=2, floatmode='fixed')
        print("Matriks Awal :")
        print(str(self.arr).replace('[[',' [').replace(']]',']').replace(']',' ]').replace('[  ','[ '))
        for i in range(m):
            r = np.argmax(abs(self.arr[i:, i])) + i
            self.arr[[i, r]] = self.arr[[r, i]]
            # print(f"\nIterasi {i + 1} - Pivoting:")
            # print(self.arr)
            v = self.arr[i, i]
            self.arr[i] /= v
            print(f"\nB{i+1} = B{i+1} / {v}")
            print(str(self.arr).replace('[[',' [').replace(']]',']').replace(']',' ]').replace('[  ','[ '))
            for j in range(m):
                if j != i:
                    f = self.arr[j, i]
                    self.arr[j] -= f * self.arr[i]
                    if f == 0.0: pass
                    else:
                        print(f"\nB{j+1} = B{j+1} - (B{i+1}*{f})")
                        print(str(self.arr).replace('[[',' [').replace(']]',']').replace(']',' ]').replace('[  ','[ '))
        print("\nMatriks Akhir :")
        print(str(self.arr).replace('[[',' [').replace(']]',']').replace(']',' ]').replace('[  ','[ '))
        s = self.arr[:, -1]
        print("\nSolusi Sistem Persamaan Linear :")
        print(s)
        print('')

if __name__ == '__main__': clear(); gjd_ordo_3x4()