#include <iostream>
#include <chrono>//per il timer
#include <unistd.h>//per sleep
#include<vector>
#include <algorithm> //per generate
#include <sstream>
#include "SortingAlgorithm.hpp"
using namespace std;

template<typename T>
double durationBubble(vector<T>& data){
    chrono::steady_clock::time_point t_begin=chrono::steady_clock::now();
    SortLibrary::BubbleSort(data);
    chrono::steady_clock::time_point t_end=chrono::steady_clock::now();
    double tempo=chrono::duration_cast<chrono::nanoseconds>(t_end-t_begin).count();
    return tempo;

    }

template<typename T>
double durationMerge(vector<T>& data){
    chrono::steady_clock::time_point t_begin=chrono::steady_clock::now();
    SortLibrary::MergeSort(data);
    chrono::steady_clock::time_point t_end=chrono::steady_clock::now();
    double tempo=chrono::duration_cast<chrono::nanoseconds>(t_end-t_begin).count();
    return tempo;
}


int main(int k, char **a)
{
    stringstream ss;
    ss<<a[1];
    int b;
    ss>>b;
    cout<<b;

    // vettore tutto ordinato
    int rep=10;
    vector<int> v(b);
    vector<int> v1(b);
    int n=0;
    generate(v.begin(), v.end(), [&n] () {return n++;}); //crea un vettore partendo da begin con numeri interni sempre diversi
    double sommaB=0;
    double sommaM=0;
    for (unsigned int i=0; i<rep; i++){
    sommaB=sommaB+durationBubble(v);
    sommaM=sommaM+durationMerge(v);
    }
    double tempoB=sommaB/rep;
    double tempoM=sommaM/rep;
    cout<<"con i vettori ordinati ottengo:"<<endl;
    cout<<"con Bubble -->"<<tempoB<<endl<<"con Mergesort -->"<<tempoM<<endl;

    // vettore tutto decrescente

    sommaB=0;
    sommaM=0;
    for (unsigned int i=0; i<rep; i++){
        n=b;
        generate(v.begin(), v.end(), [&n] () {return n--;});
        v1=v;
        sommaB=sommaB+durationBubble(v);
        sommaM=sommaM+durationMerge(v1);
    }
    tempoB=sommaB/rep;
    tempoM=sommaM/rep;
    cout<<"con i vettori ordinati ottengo:"<<endl;
    cout<<"con Bubble -->"<<tempoB<<endl<<"con Mergesort -->"<<tempoM<<endl;

    // vettore con un terzo randomico e il resto finale ordinato

    sommaB=0;
    sommaM=0;
    for (unsigned int i=0; i<rep; i++){
        n=0;
        generate(v.begin(), v.end(), [&n] () {return n++;});

        for (unsigned j=0; j<(b/3); j++){
            v[j] =rand() % (3*b/2);
        }
        v1=v;
        sommaB=sommaB+durationBubble(v);
        sommaM=sommaM+durationMerge(v1);
    }
    tempoB=sommaB/rep;
    tempoM=sommaM/rep;
    cout<<"con il primo terzo di vettore casuale e il resto ordinato ottengo:"<<endl;
    cout<<"con Bubble -->"<<tempoB<<endl<<"con Mergesort -->"<<tempoM<<endl;
    // due terzi iniziali randomici

    sommaB=0;
    sommaM=0;
    for (unsigned int i=0; i<rep; i++){
        n=0;
        generate(v.begin(), v.end(), [&n] () {return n++;});

        for (unsigned j=0; j<((2*b)/3); j++){
            v[j] =rand() % (3*b/2);
        }
        v1=v;
        /*for (unsigned j=0; j<b; j++){
            cout<<v[j]<<" ";
        }
        cout<<endl;
        for (unsigned j=0; j<b; j++){
            cout<<v1[j]<<" ";
        }
        cout<<endl;*/
        sommaB=sommaB+durationBubble(v);
        sommaM=sommaM+durationMerge(v1);
    }
    tempoB=sommaB/rep;
    tempoM=sommaM/rep;
    cout<<"con i primi due terzi di vettore casuale e il resto ordinato ottengo:"<<endl;
    cout<<"con Bubble -->"<<tempoB<<endl<<"con Mergesort -->"<<tempoM<<endl;
    // metà randomici

    sommaB=0;
    sommaM=0;
    for (unsigned int i=0; i<rep; i++){
        n=0;
        generate(v.begin(), v.end(), [&n] () {return n++;});

        for (unsigned j=0; j<b/2; j++){
            v[j] =rand() % (3*b/2);
        }
        v1=v;
        sommaB=sommaB+durationBubble(v);
        sommaM=sommaM+durationMerge(v1);
    }
    tempoB=sommaB/rep;
    tempoM=sommaM/rep;
    cout<<"con metà vettore casuale e il resto ordinato ottengo:"<<endl;
    cout<<"con Bubble -->"<<tempoB<<endl<<"con Mergesort -->"<<tempoM<<endl;
    // ultimo terzo randomici
    sommaB=0;
    sommaM=0;
    for (unsigned int i=0; i<rep; i++){
        n=0;
        generate(v.begin(), v.end(), [&n] () {return n++;});

        for (unsigned j=b; j>(2*b/3); --j){
            v[j] =rand() % (3*b/2);
        }
        v1=v;

        sommaB=sommaB+durationBubble(v);
        sommaM=sommaM+durationMerge(v1);
    }
    tempoB=sommaB/rep;
    tempoM=sommaM/rep;
    cout<<"con ultimo terzo di vettore ordinato e il resto ordinato ottengo:"<<endl;
    cout<<"con Bubble -->"<<tempoB<<endl<<"con Mergesort -->"<<tempoM<<endl;

    // ultimi due terzi randomici

    sommaB=0;
    sommaM=0;
    for (unsigned int i=0; i<rep; i++){
        n=0;
        generate(v.begin(), v.end(), [&n] () {return n++;});

        for (unsigned j=b; j>b/3; --j){
            v[j] =rand() % (3*b/2);
        }
        v1=v;
        sommaB=sommaB+durationBubble(v);

        sommaM=sommaM+durationMerge(v1);
    }
    tempoB=sommaB/rep;
    tempoM=sommaM/rep;
    cout<<"con ultimo due terzo di vettore casuale e il resto ordinato ottengo:"<<endl;
    cout<<"con Bubble -->"<<tempoB<<endl<<"con Mergesort -->"<<tempoM<<endl;

    //vettore tutto randomico


    sommaB=0;
    sommaM=0;
    for (unsigned int i=0; i<rep; i++){
        for (unsigned j=b; j>(b/3); --j){
            v[j] =rand() % (3*b/2);
        }
        v1=v;
        sommaB=sommaB+durationBubble(v);
        sommaM=sommaM+durationMerge(v1);
    }
    tempoB=sommaB/rep;
    tempoM=sommaM/rep;
    cout<<"con tutto randomico ottengo:"<<endl;
    cout<<"con Bubble -->"<<tempoB<<endl<<"con Mergesort -->"<<tempoM<<endl;

    cout<<"dai risultati emerge che la velocita' di Bubblesort varia molto a seconda di dove si trovano gli elementi randomici"<<
        ". Bubble e' piu' veloce se non sono modificate le ultime parti del vettore; invece e' piu' lento se vengono modificate le ultime parti del vettore"<<
        "invece Merge mantiene quasi sempre la stessa velocita', tranne se il vettore e' molto piu' ordinato"<<
        ". Complessivamente Merge e' sempre piu' veloce del Bubble a parte quando si trattano vettori ordinati";

    return 0;
}

