#include <iostream>
#include <conio.h>


struct uzel
    {
        int v1;
        int v2;
        int wes;
    };
struct Graf
{
    int MaxNodes;
    int* nodes;
    int num_vershina{};
    int num_ribs{};
    int Last_vertex{};
	uzel* nodez;
    Graf()
	{
    MaxNodes = 50;
    nodes = new int[MaxNodes];
    nodez = new uzel[MaxNodes];
}
    
    

};




void InitGraf(Graf* graf)
{
    std::cout << "Enter the number of vertices" << std::endl;
    std::cin >> graf->num_vershina;
    std::cout << std::endl << "Enter the number of ribs" << std::endl;
    std::cin >> graf->num_ribs;

    
    for (int i = 0; i < graf->num_vershina; i++)
        graf->nodes[i] = -1 - i;
    std::cout << std::endl
        << "Number of ribs :" << graf->num_ribs << std::endl;
    for (int i = 0; i < graf->num_ribs; i++)
    {
	    std::cout << std::endl << "Vertex 1 = ";
	    std::cin >> graf->nodez[i].v1;
	    std::cout << "Vertex 2 = ";
	    std::cin >> graf->nodez[i].v2;
	    std::cout << "Weight = ";
	    std::cin >> graf->nodez[i].wes;
    }
    std::cout << std::endl << "The graph is set" << std::endl;
}


void sort(Graf* graf)
{
		uzel tmp;
    for (int i = 0; i < graf->num_ribs - 1; i++)
        for (int j = 0; j < graf->num_ribs - 1; j++)
            if (graf->nodez[j].wes > graf->nodez[j + 1].wes)
            {
                tmp = graf->nodez[j];
                graf->nodez[j] = graf->nodez[j + 1];
                graf->nodez[j + 1] = tmp;
            }

}

int GetColor(int n,Graf* graf)
{

    if (graf->nodes[n] < 0)
    {
        graf->Last_vertex = n;
        return graf->nodes[graf->Last_vertex];
    }
    else
    {
        int color;
        
        color = GetColor(graf->nodes[n],graf);
        graf->nodes[n] = graf->Last_vertex;
        return color;
    }

}


void OutputCarcass(Graf* graf)
{
    sort(graf);
    std::cout << "The minimum spanning tree consists of edges with weights " << std::endl;
    for (int i = 0; i < graf->num_ribs; i++)
    {
        int color1 = GetColor(graf->nodez[i].v2,graf);
        int color2 = GetColor(graf->nodez[i].v1,graf);  

        if (color2 != color1)
        {
            graf->nodes[graf->Last_vertex] = graf->nodez[i].v2;
            std::cout << std::endl << "v1 - " << graf->nodez[i].v1 << " " << graf->nodez[i].wes << " " << "v2 - " << graf->nodez[i].v2;
        }
    }
    std::cout << "\n";

}

int main()
{
    Graf* graf = new Graf();
			InitGraf(graf);
            OutputCarcass(graf);
            delete graf;
    
}