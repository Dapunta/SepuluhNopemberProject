import os, re, shutil, requests, zipfile

class Task_A():

    def __init__(self):
        self.source_url = 'https://dl.dropboxusercontent.com/scl/fi/gmy0qvbysh3h7vdexso9k/task_sisop.zip?rlkey=ism9qfjh82awg2tbtzfbrylg4&dl=0'
        self.current_path = os.path.basename(os.path.dirname(__file__))
        self.data = []
        self.SetPath()
        self.Dump(self.old_folder_path)
        self.Sort()
        self.Move()
        print('\rDone.                           ')

    def SetPath(self): #--> Atur Direktori

        self.old_folder_path = self.current_path + '/task_sisop'
        if os.path.exists(self.old_folder_path): pass
        else: self.Download()

        self.new_folder_path = self.current_path + '/task'
        if os.path.exists(self.new_folder_path): pass
        else: os.mkdir(self.new_folder_path)

    def Download(self): #--> Download, Ekstrak, Dan Simpan File Source

        print('\rMendownload File Zip            ', end='', flush=True)
        zip_path = self.current_path+'/task_sisop.zip'
        r = requests.Session()
        req = r.get(self.source_url).content
        open(zip_path, 'wb').write(req)

        print('\rMengekstrak File Zip            ', end='', flush=True)
        zipfile.ZipFile(zip_path, 'r').extractall(self.old_folder_path)

        print('\rMenghapus File Zip              ', end='', flush=True)
        os.remove(zip_path)

    def Dump(self, folder_path): #--> Mengumpulkan File Berakhiran (.txt) Dari Berbagai Folder
        print('\rMengumpulkan File .txt          ', end='', flush=True)
        for item in os.listdir(folder_path):
            item_path = '{}/{}'.format(folder_path, item)
            if os.path.isdir(item_path):
                self.Dump(item_path)
            else:
                if item_path.endswith('.txt'):
                    self.data.append(item_path)

    def Sort(self): #--> Mengurutkan Task Dari Yang Terkecil
        for i in range(len(self.data)-1):
            for j in range(len(self.data)-i-1):
                ongko_kiwo   = int(re.search(r'_(\d+)_',str(self.data[j])).group(1))
                ongko_tengen = int(re.search(r'_(\d+)_',str(self.data[j+1])).group(1))
                if ongko_kiwo > ongko_tengen:
                    self.data[j], self.data[j+1] = self.data[j+1], self.data[j]

    def Move(self): #--> Memindahkan File Yang Telah Disortir
        print("\rMenyimpan File Ke Folder 'task' ", end='', flush=True)
        for i in self.data:
            shutil.copy(i, self.new_folder_path)
        
        print("\rMenghapus Folder 'task_sisop'   ", end='', flush=True)
        shutil.rmtree(self.old_folder_path)

if __name__ == '__main__':
    Task_A()