import os, sys

def clear():
    os.system('clear' if 'linux' in sys.platform.lower() else 'cls')

def headers():
    print('[ Num To Text ]\n')
    print('Tools Untuk Generate Sebuah Angka/Bilangan\nMenjadi Sebuah Teks Secara Utuh\n')
    print('Batasan :')
    print('  - Max : 9999')
    print('  - Min : 0\n')

class angka_to_teks():
    def __init__(self,object=None):
        self.angka = int(input('Masukkan Angka : '))
        # self.angka = 9910
        # print(self.angka)
        if len(str(self.angka)) == 4: #--> 4 Digit
            print(self.generate(' Ribu',-4,z=''),end='')
            print(self.generate(' Ratus',-3),end='')
            if int(str(self.angka)[-2]) == 1:
                print(self.generate(' Belas',-1),end='')
            else:
                print(self.generate(' Puluh',-2),end='')
                print(self.generate('',-1,a='satuan2',z=' '),end='')
            print('')
        elif len(str(self.angka)) == 3: #--> 3 Digit
            print(self.generate(' Ratus',-3,z=''),end='')
            if int(str(self.angka)[-2]) == 1:
                print(self.generate(' Belas',-1),end='')
            else:
                print(self.generate(' Puluh',-2),end='')
                print(self.generate('',-1,a='satuan2',z=' '),end='')
            print('')
        elif len(str(self.angka)) == 2: #--> 2 Digit
            if self.angka == 10: print('Sepuluh',end='')
            else:
                if int(str(self.angka)[-2]) == 1:
                    print(self.generate(' Belas',-1,z=''),end='')
                else:
                    print(self.generate(' Puluh',-2,z=''),end='')
                    print(self.generate('',-1,a='satuan2',z=' '),end='')
            print('')
        elif len(str(self.angka)) == 1: #--> 1 Digit
            print(self.generate('',-1,a='satuan',z=''),end='')
            print('')
    def generate(self,b,c,a=None,z=' '):
        d = {
            0:'', 
            1:f'{z}Se{b.lower().strip()}', 
            2:f'{z}Dua{b}', 
            3:f'{z}Tiga{b}', 
            4:f'{z}Empat{b}', 
            5:f'{z}Lima{b}', 
            6:f'{z}Enam{b}', 
            7:f'{z}Tujuh{b}', 
            8:f'{z}Delapan{b}', 
            9:f'{z}Sembilan{b}'}
        if b == ' Belas' and int(str(self.angka)[c]) == 0: return(' Sepuluh')
        elif a == 'satuan':
            if int(str(self.angka)[c]) == 0: return('Nol')
            elif int(str(self.angka)[c]) == 1: return('Satu')
            else: return(d[int(str(self.angka)[c])])
        elif a == 'satuan2':
            if int(str(self.angka)[c]) == 0: return('')
            elif int(str(self.angka)[c]) == 1: return(' Satu')
            else: return(d[int(str(self.angka)[c])])
        else: return(d[int(str(self.angka)[c])])

if __name__ == '__main__':
    clear()
    headers()
    while True:
        angka_to_teks()
        print('')