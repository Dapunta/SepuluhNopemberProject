// keterangan soal a :
// 1. instalasi kaggle : pip install kaggle --user
// 2. taro instalasa ke path : export PATH="$PATH:$HOME/.local/bin"
// 3. cek kaggle : kaggle --version
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE_LENGTH 256
#define MAX_LINE_LENGTH_Atribut 1024
#define MAX_NAME_LENGTH 50

typedef struct
{
    char Nama[MAX_NAME_LENGTH];
    char Role[MAX_NAME_LENGTH];
    char Tipe[MAX_NAME_LENGTH];
    int Tahun_Rilis;
} Hero;

typedef struct
{
    char Nama[MAX_NAME_LENGTH];
    int HP;
    float HP_Regen;
    int Physical_Attack;
    int Physical_Defence;
    float Attack_Speed;
    int Attack_Speed_pc;
    int Mana;
    int Mana_Regen;
    int Magic_Power;
    int Magic_Defence;
    int Movement_Speed;
    float Critical_Chance;
    int Critical_Damage;
    int Critical_Damage_Reduction;
    int Cooldown_Reduction;
    int Spell_Vamp;
    int Magic_Lifesteal;
    int Physical_PEN;
    int Physical_PEN_Persen;
    int Magical_PEN;
    int Magical_PEN_Persen;
    int Resilience;
    int Efek_Pemulihan;
    int Pemulihan_Diterima;
    float Attack_Speed_Total;
} AtributHero;

// soal a
void downloadDataset()
{
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0)
    {
        // Child process
        // system("apt install python3-xyz");
        // system("pip install kaggle");
        // system("export PATH='$PATH : $HOME /.local / bin'");
        // system("export PATH='$PATH:$HOME/.local/bin'");
        // system("kaggle datasets download -d irwansyah10010/mobilelegend");
        execlp("kaggle", "kaggle", "datasets", "download", "-d", "irwansyah10010/mobilelegend", NULL);
        perror("Exec failed");
        exit(EXIT_FAILURE);
    }
    else
    {
        // Parent process
        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
        {
            printf("Dataset downloaded successfully.\n");
        }
        else
        {
            printf("Failed to download dataset.\n");
            exit(EXIT_FAILURE);
        }
    }
}

void extractDataset()
{
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0)
    {
        // system("ls");
        // system("unzip mobilegend.zip");
        // Child process
        execlp("unzip", "unzip", "mobilelegend.zip", NULL);
        perror("Exec failed");
        exit(EXIT_FAILURE);
    }
    else
    {
        // Parent process
        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
        {
            printf("Dataset extracted successfully.\n");
        }
        else
        {
            printf("Failed to extract dataset.\n");
            exit(EXIT_FAILURE);
        }
    }
}

// akhir a

void parseAtributCSV(const char *filename, AtributHero atributHeroes[], int *numAtributHeroes)
{
    char filepath[256];
    snprintf(filepath, sizeof(filepath), "Data Mobile Legend/Atribut/%s", filename);

    FILE *file = fopen(filepath, "r");
    if (file == NULL)
    {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH_Atribut];
    *numAtributHeroes = 0;

    // Skip header line
    fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file) != NULL)
    {
        // Parse line
        char *token = strtok(line, ";");
        strcpy(atributHeroes[*numAtributHeroes].Nama, token);

        token = strtok(NULL, ";");
        atributHeroes[*numAtributHeroes].HP = atoi(token);

        token = strtok(NULL, ";");
        atributHeroes[*numAtributHeroes].HP_Regen = atof(token);

        token = strtok(NULL, ";");
        atributHeroes[*numAtributHeroes].Physical_Attack = atoi(token);

        token = strtok(NULL, ";");
        atributHeroes[*numAtributHeroes].Physical_Defence = atoi(token);

        token = strtok(NULL, ";");
        atributHeroes[*numAtributHeroes].Attack_Speed = atof(token);

        token = strtok(NULL, ";");
        atributHeroes[*numAtributHeroes].Attack_Speed_pc = atoi(token);

        token = strtok(NULL, ";");
        atributHeroes[*numAtributHeroes].Mana = atoi(token);

        token = strtok(NULL, ";");
        atributHeroes[*numAtributHeroes].Mana_Regen = atoi(token);

        token = strtok(NULL, ";");
        atributHeroes[*numAtributHeroes].Magic_Power = atoi(token);

        token = strtok(NULL, ";");
        atributHeroes[*numAtributHeroes].Magic_Defence = atoi(token);

        token = strtok(NULL, ";");
        atributHeroes[*numAtributHeroes].Movement_Speed = atoi(token);

        token = strtok(NULL, ";");
        atributHeroes[*numAtributHeroes].Critical_Chance = atof(token);

        token = strtok(NULL, ";");
        atributHeroes[*numAtributHeroes].Critical_Damage = atoi(token);

        token = strtok(NULL, ";");
        atributHeroes[*numAtributHeroes].Critical_Damage_Reduction = atoi(token);

        token = strtok(NULL, ";");
        atributHeroes[*numAtributHeroes].Cooldown_Reduction = atoi(token);

        token = strtok(NULL, ";");
        atributHeroes[*numAtributHeroes].Spell_Vamp = atoi(token);

        token = strtok(NULL, ";");
        atributHeroes[*numAtributHeroes].Magic_Lifesteal = atoi(token);

        token = strtok(NULL, ";");
        atributHeroes[*numAtributHeroes].Physical_PEN = atoi(token);

        token = strtok(NULL, ";");
        atributHeroes[*numAtributHeroes].Physical_PEN_Persen = atoi(token);

        token = strtok(NULL, ";");
        atributHeroes[*numAtributHeroes].Magical_PEN = atoi(token);

        token = strtok(NULL, ";");
        atributHeroes[*numAtributHeroes].Magical_PEN_Persen = atoi(token);

        token = strtok(NULL, ";");
        atributHeroes[*numAtributHeroes].Resilience = atoi(token);

        token = strtok(NULL, ";");
        atributHeroes[*numAtributHeroes].Efek_Pemulihan = atoi(token);

        token = strtok(NULL, ";");
        atributHeroes[*numAtributHeroes].Pemulihan_Diterima = atoi(token);

        token = strtok(NULL, ";");
        atributHeroes[*numAtributHeroes].Attack_Speed_Total = atof(token);

        (*numAtributHeroes)++;
    }

    fclose(file);
}

void parseCSV(const char *filename, Hero heroes[], int *numHeroes)
{
    char filepath[256];
    snprintf(filepath, sizeof(filepath), "Data Mobile Legend/%s", filename);

    FILE *file = fopen(filepath, "r");
    if (file == NULL)
    {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    *numHeroes = 0;

    // Skip header line
    fgets(line, sizeof(line), file);
    while (fgets(line, sizeof(line), file) != NULL)
    {
        // Skip empty lines
        if (line[0] == '\n' || line[0] == '\0')
        {
            continue;
        }

        // Parse line
        char *token = strtok(line, ";");
        strcpy(heroes[*numHeroes].Nama, token);

        token = strtok(NULL, ";");
        strcpy(heroes[*numHeroes].Role, token);

        token = strtok(NULL, ";");
        strcpy(heroes[*numHeroes].Tipe, token);

        token = strtok(NULL, ";");
        heroes[*numHeroes].Tahun_Rilis = atoi(token);

        (*numHeroes)++;
    }

    fclose(file);
}

void writeToFile(const char *filename, Hero heroes[], int numHeroes)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        perror("Failed to create file");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "Nama\t\tRole\n");
    for (int i = 0; i < numHeroes; i++)
    {
        fprintf(file, "%s\t\t%s\n", heroes[i].Nama, heroes[i].Role);
    }

    fclose(file);
}

void bestTank(Hero heroes[], AtributHero atributHeroes[], int numHeroes)
{
    char tempNama[50];
    int tempSkillPoint = 0;
    for (int i = 0; i < numHeroes; i++)
    {
        if (strcmp(heroes[i].Role, "TANK") == 0 || strcmp(heroes[i].Role, "TANK/SUPPORT") == 0 || strcmp(heroes[i].Role, "TANK/FIGHTER") == 0 || strcmp(heroes[i].Role, "FIGHTER/TANK") == 0)
        {
            if (atributHeroes[i].HP > tempSkillPoint)
            {
                tempSkillPoint = atributHeroes[i].HP;
                strcpy(tempNama, heroes[i].Nama);
            }
        }
    }
    printf("Hero terbaik adalah %s dengan skillpoint %d\n", tempNama, tempSkillPoint);
}

void bestAsasin(Hero heroes[], AtributHero atributHeroes[], int numHeroes)
{
    char tempNama[50];
    int tempSkillPoint = 0;
    for (int i = 0; i < numHeroes; i++)
    {
        if (strcmp(heroes[i].Role, "ASSASSIN") == 0 || strcmp(heroes[i].Role, "MAGE/ASSASSIN") == 0 || strcmp(heroes[i].Role, "SUPPORT/ASSASSIN") == 0 || strcmp(heroes[i].Role, "ASSASSIN/MAGE") == 0 || strcmp(heroes[i].Role, "ASSASSIN/MM") == 0 || strcmp(heroes[i].Role, "FIGHTER/ASSASSIN") == 0)
        {
            if (atributHeroes[i].Physical_Attack > tempSkillPoint)
            {
                tempSkillPoint = atributHeroes[i].Physical_Attack;
                strcpy(tempNama, heroes[i].Nama);
            }
        }
    }
    printf("Hero terbaik adalah %s dengan skillpoint %d\n", tempNama, tempSkillPoint);
}

void bestFighter(Hero heroes[], AtributHero atributHeroes[], int numHeroes)
{
    char tempNama[50];
    int tempSkillPoint = 0;
    int totalSkillPoint = 0;
    for (int i = 0; i < numHeroes; i++)
    {
        if (strcmp(heroes[i].Role, "FIGHTER") == 0 || strcmp(heroes[i].Role, "FIGHTER/MAGE") == 0 || strcmp(heroes[i].Role, "TANK/FIGHTER") == 0 || strcmp(heroes[i].Role, "FIGHTER/SUPPORT") == 0 || strcmp(heroes[i].Role, "FIGHTER/MM") == 0 || strcmp(heroes[i].Role, "FIGHTER/TANK") == 0 || strcmp(heroes[i].Role, "FIGHTER/ASSASSIN") == 0)
        {
            if (strcmp(heroes[i].Nama, "Alucard") == 0)
            {
                atributHeroes[i].HP = 2621;
            }
            if (strcmp(heroes[i].Nama, "Argus") == 0)
            {
                atributHeroes[i].Physical_Attack = 100;
            }
            totalSkillPoint = atributHeroes[i].HP + atributHeroes[i].Physical_Attack;
            if (totalSkillPoint > tempSkillPoint)
            {
                tempSkillPoint = totalSkillPoint;
                strcpy(tempNama, heroes[i].Nama);
            }
        }
    }
    printf("Hero terbaik adalah %s dengan skillpoint %d\n", tempNama, tempSkillPoint);
}

void bestMM(Hero heroes[], AtributHero atributHeroes[], int numHeroes)
{
    char tempNama[50];
    int tempSkillPoint = 0;
    int totalSkillPoint = 0;
    for (int i = 0; i < numHeroes; i++)
    {
        if (strcmp(heroes[i].Role, "MM") == 0 || strcmp(heroes[i].Role, "MM/MAGE") == 0 || strcmp(heroes[i].Role, "FIGHTER/MM") == 0 || strcmp(heroes[i].Role, "ASSASSIN/MM") == 0)
        {
            totalSkillPoint = atributHeroes[i].Physical_Attack * atributHeroes[i].Attack_Speed;
            if (totalSkillPoint > tempSkillPoint)
            {
                tempSkillPoint = totalSkillPoint;
                strcpy(tempNama, heroes[i].Nama);
            }
        }
    }
    printf("Hero terbaik adalah %s dengan skillpoint %d\n", tempNama, tempSkillPoint);
}

void bestMage(Hero heroes[], AtributHero atributHeroes[], int numHeroes)
{
    char tempNama[50];
    int tempSkillPoint = 0;
    int totalSkillPoint = 0;
    for (int i = 0; i < numHeroes; i++)
    {
        if (strcmp(heroes[i].Role, "MAGE") == 0 || strcmp(heroes[i].Role, "FIGHTER/MAGE") == 0 || strcmp(heroes[i].Role, "MAGE/ASSASSIN") == 0 || strcmp(heroes[i].Role, "MM/MAGE") == 0 || strcmp(heroes[i].Role, "MAGE/SUPPORT") == 0 || strcmp(heroes[i].Role, "ASSASSIN/MAGE") == 0)
        {
            totalSkillPoint = atributHeroes[i].Mana / atributHeroes[i].Mana_Regen;
            if (totalSkillPoint > tempSkillPoint)
            {
                tempSkillPoint = totalSkillPoint;
                strcpy(tempNama, heroes[i].Nama);
            }
        }
    }
    printf("Hero terbaik adalah %s dengan skillpoint %d\n", tempNama, tempSkillPoint);
}

void bestSupport(Hero heroes[], AtributHero atributHeroes[], int numHeroes)
{
    char tempNama[50];
    int tempSkillPoint = 0;
    int totalSkillPoint = 0;
    for (int i = 0; i < numHeroes; i++)
    {
        if (strcmp(heroes[i].Role, "SUPPORT") == 0 || strcmp(heroes[i].Role, "TANK/SUPPORT") == 0 || strcmp(heroes[i].Role, "FIGHTER/SUPPORT") == 0 || strcmp(heroes[i].Role, "SUPPORT/ASSASSIN") == 0 || strcmp(heroes[i].Role, "MAGE/SUPPORT") == 0)
        {
            totalSkillPoint = atributHeroes[i].Mana_Regen + atributHeroes[i].HP;
            if (totalSkillPoint > tempSkillPoint)
            {
                tempSkillPoint = totalSkillPoint;
                strcpy(tempNama, heroes[i].Nama);
            }
        }
    }
    printf("Hero terbaik adalah %s dengan skillpoint %d\n", tempNama, tempSkillPoint);
}

int main(int argc, char *argv[])
{
    downloadDataset();
    extractDataset();
    if (argc == 1)
    {
        // Define array of AtributHero structs
        AtributHero atributHeroes[120];
        int numAtributHeroes;
        parseAtributCSV("atribut-hero.csv", atributHeroes, &numAtributHeroes);

        // Define array of Hero structs
        Hero heroes[120];
        int numHeroes;
        parseCSV("identitas.csv", heroes, &numHeroes);

        bestTank(heroes, atributHeroes, numHeroes);
        bestAsasin(heroes, atributHeroes, numHeroes);
        bestFighter(heroes, atributHeroes, numHeroes);
        bestMM(heroes, atributHeroes, numHeroes);
        bestMage(heroes, atributHeroes, numHeroes);
        bestSupport(heroes, atributHeroes, numHeroes);
    }

    if (argc == 2)
    {
        char *myString;

        // Mengalokasikan memori untuk myString dengan panjang yang sesuai
        myString = (char *)malloc(strlen(argv[1]) + 1);

        // Menyalin nilai argv ke myString
        strcpy(myString, argv[1]);

        // Define array of AtributHero structs
        AtributHero atributHeroes[120];
        int numAtributHeroes;
        parseAtributCSV("atribut-hero.csv", atributHeroes, &numAtributHeroes);

        // Define array of Hero structs
        Hero heroes[120];
        int numHeroes;
        parseCSV("identitas.csv", heroes, &numHeroes);

        if (strcmp(myString, "Tank") == 0)
        {
            bestTank(heroes, atributHeroes, numHeroes);
        }
        if (strcmp(myString, "Assassin") == 0)
        {
            bestAsasin(heroes, atributHeroes, numHeroes);
        }
        if (strcmp(myString, "Fighter") == 0)
        {
            bestFighter(heroes, atributHeroes, numHeroes);
        }
        if (strcmp(myString, "Marksman") == 0)
        {
            bestMM(heroes, atributHeroes, numHeroes);
        }
        if (strcmp(myString, "Mage") == 0)
        {
            bestMage(heroes, atributHeroes, numHeroes);
        }
        if (strcmp(myString, "Support") == 0)
        {
            bestSupport(heroes, atributHeroes, numHeroes);
        }
    }
    return 0;
}
