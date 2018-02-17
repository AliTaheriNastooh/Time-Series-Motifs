#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "saxquantizer.hpp"
#include <sstream>
#include <string>

using namespace std;
int alphabetSize=10;
int wordSize=8;
int margin=1;
int main(int argc, char **argv) {
    ifstream infile("C:\\Users\\ali taheri\\CLionProjects\\untitled\\dataset.txt");
    ofstream outfile("C:\\Users\\ali taheri\\CLionProjects\\untitled\\out8_cpp.txt");
    vector<int> out;
    vector<double>inp;
    string line1;

    outfile<<alphabetSize<<" "<<wordSize<<" "<<margin<<endl;
    int counter1=0;
    while(getline( infile, line1 ))
    {
        counter1++;

        stringstream iss(line1);
        int counter=0;
        double a;
        while(true) {
            if (!(iss >> a)) {
                break;


            } else {
                inp.push_back(a);
                counter++;
            } // error
        }
        SaxQuantizer::Sax sax(counter, wordSize, alphabetSize);
        sax.quantize(inp, &out, false);

        char c;
        for(int i=0;i<wordSize;i++){
            c=out[i]+'a';
            outfile<<c;
        }
        outfile<<endl;
        inp.clear();
        out.clear();

        // process pair (a,b)
    }

    /*
  SaxQuantizer::Sax sax(4, 1, 10);
  vector<double> input = { 1, 1, 1, 1, 2, 2, 10, 10, 100 };
  vector<int> output;
  sax.quantize(input, &output, false); // true for reduction
    sax.order();
  cout << "input:";
  for (const auto & x : input) cout << " " << x;
  cout << endl;

  cout << "output:";
  for (const auto & x : output) cout << " " << x;
  cout << endl<<sax.order();
     */
    return 0;
}