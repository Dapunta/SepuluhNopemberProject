import os, sys
def clear(): os.system('clear' if 'linux' in sys.platform.lower() else 'cls')

class main():
    def __init__(self):
        self.case = 0
        self.data = {}
        self.kartu = {'6':1,'7':2,'8':3,'9':4,'T':5,'J':6,'Q':7,'K':8,'A':9}
        self.simbol = ['S','C','D','H']
        self._takon_()
        #print(self.data)
        #print('')
        self._exec_()
    def _takon_(self):
        T = int(input(''))
        for x in range(1,T+1):
            self.case += 1
            self._input1_()
    def _input1_(self):
        N, M, R = input('').upper().split(' ')
        kartu_kita = input('').upper().split(' ')
        kartu_lawan = input('').upper().split(' ')
        self.data.update({self.case:{'kita':kartu_kita,'lawan':kartu_lawan,'truf':R}})
    def _exec_(self):
        for y,x in self.data.items():
            #print(x)
            hapus = []
            for a in x['lawan']:
                stat = 0
                o = x['kita']
                for b in o:
                    if stat == 0:
                        if b[-1] == a[-1]:
                            if self.kartu[b[0]] > self.kartu[a[0]]:
                                stat += 1
                                #print(b,'Menang Lawan',a)
                                hapus.append(a)
                for b in o:
                    if stat == 0:
                        if b[-1] == x['truf']:
                            stat += 1
                            #print(b,'Menang Lawan',a)
                            hapus.append(a)
                            o = o.remove(b)
            #print(hapus)
            for s in hapus: self.data[y]['lawan'].remove(s)
            if len(self.data[y]['lawan']) == 0:
                print('YA')
            else:
                print('TIDAK')
            #print('')

if __name__ == '__main__': clear(); main()