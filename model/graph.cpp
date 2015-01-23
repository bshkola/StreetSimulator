#include "../model/graph.h"

Graph::Graph()
{   //empty

}

Graph::~Graph()
{   //empty, we have local vertex not dynamic
    for(Vertex *ver: vertices)
        delete ver;
}

void Graph::addVertex(const NameOfVertex &coor, bool isRoad)
{   //done
    this->vertices.push_back(new Vertex(coor, isRoad));
}

void Graph::addEdge(const NameOfVertex source, int si, const NameOfVertex dest, int di)
{   //done
    list<Vertex*>::const_iterator findSour = find(source);
    list<Vertex*>::const_iterator findDest = find(dest);
    if(findSour == vertices.end() || findDest == vertices.end())
    {
        throw runtime_error("Error trying insert edge into graph, doesn't exist vertex which is on end of one edge");
    }
    (*findSour)->connect_edge(*findDest, di);
    (*findDest)->connect_edge(*findSour, si);
}

Vertex *Graph::getVertex(const NameOfVertex vert) const
{   //done
   list<Vertex*>::const_iterator foundVertex = find(vert);
   return *foundVertex;
}

bool Graph::isExist(const NameOfVertex &coor) const
{   //done
    list<Vertex*>::const_iterator finder = find(coor);
    if(finder != vertices.end()){
        return true;
    }else{
        return false;
    }
}

string Graph::toString() const
{
    std::stringstream ret;
    ret << "grap////////////////////: "<<std::endl;
    for(Vertex *ver: vertices)
    {
        ret << "(" << ver->getName().first << ", " << ver->getName().second << ")";
        for(int i = 0; i < 4; i++)
        {
            if(ver->getEdge(i).m_Edge == NULL)
                continue;
            ret << " ->> (" << ver->getEdge(i).m_Edge->getName().first
                << ", " << ver->getEdge(i).m_Edge->getName().second << ")";
        }
        ret << std::endl;
    }
    return ret.str();
}

Vertex *Graph::end() const
{   //done
    return *(vertices.end());
}

list<Vertex*>::const_iterator Graph::find(const NameOfVertex& nameVertex) const
{
    for(list<Vertex*>::const_iterator ver = vertices.begin(); ver != vertices.end(); ++ver)
    {
        if(ver != vertices.end() && (*ver)->getName() == nameVertex)
        {
            return ver;
        }
    }
    return vertices.end();
}

void Vertex::connect_edge(Vertex *adjacent, int whatDirection)
{   //done
    this->edges[whatDirection] = Edge(adjacent);
}
