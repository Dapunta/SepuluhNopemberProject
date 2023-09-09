from flask import Flask, request, render_template
app = Flask(__name__)
import os, sys
import numpy as np
def clear(): os.system('clear' if 'linux' in sys.platform.lower() else 'cls')

@app.route('/',methods=['GET','POST'])
def index():
    clear()
    global dataray
    if request.method == 'POST':
        try:
            x1,y1,z1,v1 = [request.form.get(i) for i in ['x1','y1','z1','v1']]
            x2,y2,z2,v2 = [request.form.get(i) for i in ['x2','y2','z2','v2']]
            x3,y3,z3,v3 = [request.form.get(i) for i in ['x3','y3','z3','v3']]
            dataray = [[x1,y1,z1,v1],[x2,y2,z2,v2],[x3,y3,z3,v3]]
            print(dataray)
            solver = gjd_ordo_3x4()
            output = solver.solve()
            return render_template('index.html', output=output)
        except Exception as e:
            return render_template('index.html', notice='Terjadi Kesalahan!')
    else:
        return render_template('index.html')

class gjd_ordo_3x4():
    def __init__(self):
        self.arr = np.array(dataray,dtype=float)
    def solve(self):
        m, n = self.arr.shape
        np.set_printoptions(precision=2, floatmode='fixed')
        output = []
        output.append("Matriks Awal :")
        output.append(str(self.arr).replace('[[',' [').replace(']]',']').replace(']',' ]').replace('[  ','[ '))
        print("Matriks Awal :")
        print(str(self.arr).replace('[[',' [').replace(']]',']').replace(']',' ]').replace('[  ','[ '))
        print(self.arr)
        for i in range(m):
            r = np.argmax(abs(self.arr[i:, i])) + i
            self.arr[[i, r]] = self.arr[[r, i]]
            v = self.arr[i, i]
            self.arr[i] /= v
            output.append(f"\nB{i+1} = B{i+1} / {v}")
            output.append(str(self.arr).replace('[[',' [').replace(']]',']').replace(']',' ]').replace('[  ','[ '))
            print(f"\nB{i+1} = B{i+1} / {v}")
            print(str(self.arr).replace('[[',' [').replace(']]',']').replace(']',' ]').replace('[  ','[ '))
            for j in range(m):
                if j != i:
                    f = self.arr[j, i]
                    self.arr[j] -= f * self.arr[i]
                    if f == 0.0: pass
                    else:
                        output.append(f"\nB{j+1} = B{j+1} - (B{i+1}*{f})")
                        output.append(str(self.arr).replace('[[',' [').replace(']]',']').replace(']',' ]').replace('[  ','[ '))
                        print(f"\nB{j+1} = B{j+1} - (B{i+1}*{f})")
                        print(str(self.arr).replace('[[',' [').replace(']]',']').replace(']',' ]').replace('[  ','[ '))
        output.append("\nMatriks Akhir :")
        output.append(str(self.arr).replace('[[',' [').replace(']]',']').replace(']',' ]').replace('[  ','[ '))
        print("\nMatriks Akhir :")
        print(str(self.arr).replace('[[',' [').replace(']]',']').replace(']',' ]').replace('[  ','[ '))
        s = self.arr[:, -1]
        output.append("\nSolusi Sistem Persamaan Linear :")
        output.append(str(s))
        print("\nSolusi Sistem Persamaan Linear :")
        print(s)
        return output

if __name__ == '__main__':
    app.run(debug=True)
