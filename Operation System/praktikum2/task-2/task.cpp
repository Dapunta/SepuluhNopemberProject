#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <experimental/filesystem>
#include <curl/curl.h>
#include <zip.h>

using namespace std;

namespace fs = std::experimental::filesystem;

class Task_A
{
public:
    Task_A()
    {
        source_url = "https://dl.dropboxusercontent.com/scl/fi/gmy0qvbysh3h7vdexso9k/task_sisop.zip?rlkey=ism9qfjh82awg2tbtzfbrylg4&dl=0";
        current_path = fs::path(__FILE__).parent_path().filename().string();
        SetPath();
        Dump(old_folder_path);
        Sort();
        Move();
        cout << "\rDone.                           " << endl;
    }

private:
    string source_url;
    string current_path;
    vector<string> data;
    string old_folder_path;
    string new_folder_path;

    void SetPath()
    {
        old_folder_path = current_path + "/task_sisop";
        if (fs::exists(old_folder_path))
        {
        }
        else
            Download();

        new_folder_path = current_path + "/task";
        if (fs::exists(new_folder_path))
        {
        }
        else
            fs::create_directory(new_folder_path);
    }

    void Download()
    {
        cout << "\rMendownload File Zip            ";
        string zip_path = current_path + "/task_sisop.zip";
        CURL *curl;
        FILE *fp;
        curl = curl_easy_init();
        if (curl)
        {
            fp = fopen(zip_path.c_str(), "wb");
            curl_easy_setopt(curl, CURLOPT_URL, source_url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
            curl_easy_perform(curl);
            curl_easy_cleanup(curl);
            fclose(fp);
        }

        cout << "\rMengekstrak File Zip            ";
        zip::ZipFile zipfile(zip_path);
        zipfile.extractall(old_folder_path);

        cout << "\rMenghapus File Zip              ";
        remove(zip_path.c_str());
    }

    void Dump(string folder_path)
    {
        cout << "\rMengumpulkan File .txt          ";
        for (const auto &item : fs::directory_iterator(folder_path))
        {
            string item_path = item.path();
            if (fs::is_directory(item_path))
            {
                Dump(item_path);
            }
            else
            {
                if (item_path.find(".txt") != string::npos)
                {
                    data.push_back(item_path);
                }
            }
        }
    }

    void Sort()
    {
        for (size_t i = 0; i < data.size() - 1; ++i)
        {
            for (size_t j = 0; j < data.size() - i - 1; ++j)
            {
                int ongko_kiwo = stoi(regex_search(data[j], regex("_(\\d+)_")).str(1));
                int ongko_tengen = stoi(regex_search(data[j + 1], regex("_(\\d+)_")).str(1));
                if (ongko_kiwo > ongko_tengen)
                {
                    swap(data[j], data[j + 1]);
                }
            }
        }
    }

    void Move()
    {
        cout << "\rMenyimpan File Ke Folder 'task' ";
        for (const auto &i : data)
        {
            fs::copy(i, new_folder_path);
        }

        cout << "\rMenghapus Folder 'task_sisop'   ";
        fs::remove_all(old_folder_path);
    }
};

int main()
{
    Task_A task;
    return 0;
}
