import os, sys

def clear():
    os.system('clear' if 'linux' in sys.platform.lower() else 'cls')

def headers():
    print('[ Num To Text ]\n')
    print('Tools Untuk Generate Sebuah Angka/Bilangan\nMenjadi Sebuah Teks Secara Utuh\n')
    print('Batasan :')
    print('  - Max : 9999')
    print('  - Min : 0\n')

def angka_to_teks(angka=None):
    angka = int(input('Masukkan Angka : '))
    if angka < 0 or angka > 9999: print('Angka Harus Berada Pada Interval ( 0 <= angka <= 9999 )',end=' ')
    else:
        d1 = ['Nol','Satu','Dua','Tiga','Empat','Lima','Enam','Tujuh','Delapan','Sembilan']
        d2 = ['Nol','Sebelas',f'{d1[2]} Belas',f'{d1[3]} Belas',f'{d1[4]} Belas',f'{d1[5]} Belas',f'{d1[6]} Belas',f'{d1[7]} Belas',f'{d1[8]} Belas',f'{d1[9]} Belas',]
        ribuan, ratusan, puluhan, satuan = angka//1000, (angka%1000)//100, (angka%100)//10, (angka%10)
        if angka == 0: print('Nol',end=' ')
        if ribuan > 0:
            if ribuan == 1: print('Seribu',end=' ')
            else: print('%s Ribu'%(d1[ribuan]),end=' ')
        if ratusan > 0:
            if ratusan == 1: print('Seratus',end=' ')
            else: print('%s Ratus'%(d1[ratusan]),end=' ')
        if puluhan > 0:
            if puluhan == 1 and satuan == 0: print('Sepuluh',end=' ')
            elif puluhan > 1 and satuan == 0: print('%s Puluh'%(d1[puluhan]),end=' ')
            elif puluhan == 1 and satuan > 0: print('%s'%(d2[satuan]),end=' ')
            elif puluhan > 1 and satuan > 0: print('%s Puluh %s'%(d1[puluhan],d1[satuan]),end=' ')
        if puluhan == 0 and satuan > 0: print('%s'%(d1[satuan]),end=' ')

if __name__ == '__main__':
    clear()
    headers()
    while True:
        angka_to_teks()
        print('\n')