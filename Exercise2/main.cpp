#include <iostream>
#include <fstream>
#include <iomanip>

double mappa(double x)
{
    double y= (3.0/4.0)*x-(7.0/4.0);
    return y;
}

int main()
{
    std::string fileName = "data.csv";
    std::ifstream fileDati;
    fileDati.open(fileName);

    if(fileDati.fail())
    {
        std::cerr << "Il file: " << fileName << "non esiste" << std::endl;
        return 1;
    }

    std::string fileName2 = "result.csv";
    std::ofstream fileOutput(fileName2);


    if(fileOutput.fail())
    {
        std::cerr << "Il file: " << fileName2 << " non è stato creato/aperto" << std::endl;
        return 2;
    }

    fileOutput << std::scientific;
    fileOutput << std::setprecision(16);

    fileOutput << " # N mean" << "\n";
    double valore = 0.0;
    double somma = 0.0;
    unsigned int conto=1;
    while (fileDati >> valore)
    {
        double valoreTrasformato = mappa(valore);

        somma+=valoreTrasformato;
        double media = somma/conto;

        fileOutput << conto << " " << std::scientific << std::setprecision(16) << media << std::endl;

        conto ++;
    }


    fileDati.close();
    fileOutput.close();
    return 0;
}

