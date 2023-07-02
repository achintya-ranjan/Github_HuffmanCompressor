#ifndef HUFFMAN_HPP        //to prevent header files from
#define HUFFMAN_HPP        //being included multiple times
#include <string>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

//Defining Huffman Tree Node
struct Node {
    char data;
    unsigned freq;
    string code;
    Node *left, *right;

    Node() {
        left = right = NULL;
    }
};

class huffman {
    private:
        vector <Node*> arr;
        fstream inFile, outFile;
        string inFileName, outFileName;
        Node *root;
        class Compare {
            public:
                bool operator() (Node* l, Node* r)
                {
                    return l->freq > r->freq;
                }
        };
        priority_queue <Node*, vector<Node*>, Compare> minHeap;
        //Initializing a vector of tree nodes representing character's ascii value and initializing its frequency with 0
        void createArr();
        void traverse(Node*, string);         //To traverse the constructed tree to generate huffman codes of each present character
        int binToDec(string);                 //To convert binary string to its equivalent decimal value
        string decToBin(int);                 //To convert a decimal number to its equivalent binary string
        void buildTree(char, string&);        //To reconstruct the Huffman tree while Decoding the fil
        void createMinHeap();                 //To Create a Min Heap of Nodes by frequency of characters in the input file
        void createTree();                    //To constructe the Huffman tree
        void createCodes();                   //To generate Huffman codes
        void saveEncodedFile();               //To save Huffman Encoded File
        void saveDecodedFile();               //To save Decoded File to obtain the original File
        void getTree();                       //To read the file to reconstruct the Huffman tree
    public:
        //Constructor
        huffman(string inFileName, string outFileName)
        {
            this->inFileName = inFileName;
            this->outFileName = outFileName;
            createArr();
        }                              
        
        void compress();                      //To compress the input file
        void decompress();                    //To decrompress the input file
};
#endif
