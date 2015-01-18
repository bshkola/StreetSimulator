#include "../model/dijkstra.h"

Dijkstra::Dijkstra(const Graph *graph): graph(graph)
{
std::cout<<graph->toString();
}

Dijkstra::~Dijkstra()
{
    delete graph;
}

TrafficParticipant*  Dijkstra::calculateWay(TrafficParticipant *object)
{
    list<pair<Vertex*, Vertex_str>> avaibleVertex; //vertex which we can visite
    NameOfVertex source = object -> start_point, dest = object -> target_point;   //get source & destination of point
    Vertex* tmpVertex = graph->getVertex(source);
    Vertex* destVertex = graph->getVertex(dest);  //finding a destination vertex
    avaibleVertex.push_back(make_pair(tmpVertex, Vertex_str(0, false, NULL))); //inicializate the algorithm
    pair<Vertex*, Vertex_str> tmp = avaibleVertex.back();
    while(tmp.first != destVertex && tmp.first != graph->end())
    {   //run dijkstrax
        calculateWeightForEdge(tmp.first, avaibleVertex);
        list<pair<Vertex*, Vertex_str>>::iterator it = find(avaibleVertex.begin(), avaibleVertex.end(), tmp);
        it -> second.visited = true; //mark visited vertex
        tmp = selectLeastVertix(avaibleVertex);
    }
    pair<Vertex*, Vertex_str> *tmpPoint = &tmp;
    while(tmpPoint != NULL)
    {
        object->way.push_front(tmpPoint -> first->getName());
        tmpPoint = tmpPoint->second.before;
    }
    return object;
}

void Dijkstra::calculateWeightForEdge(Vertex *ver, list<pair<Vertex*, Vertex_str>> &avaibleVertex)
{
    Edge tmp = ver->getEdge(0);
    if(tmp.m_Edge != NULL) //if exist edge in this direction
    {
        calculateValueBetweenVerteces(ver, tmp.m_Edge, avaibleVertex);
    }
    tmp = ver->getEdge(1);
    if(tmp.m_Edge != NULL) //if exist edge in this direction
    {
        calculateValueBetweenVerteces(ver, tmp.m_Edge, avaibleVertex);
    }
    tmp = ver->getEdge(2);
    if(tmp.m_Edge != NULL) //if exist edge in this direction
    {
        calculateValueBetweenVerteces(ver, tmp.m_Edge, avaibleVertex);
    }
    tmp = ver->getEdge(3);
    if(tmp.m_Edge != NULL) //if exist edge in this direction
    {
        calculateValueBetweenVerteces(ver, tmp.m_Edge, avaibleVertex);
    }
}

void Dijkstra::calculateValueBetweenVerteces(Vertex *sourceFun, Vertex *destFun,
                          list<pair<Vertex*, Vertex_str>> &avaibleVertex)
{
    list<pair<Vertex*, Vertex_str>>::iterator it;
    pair<Vertex*, Vertex_str> dest;
    pair<Vertex*, Vertex_str> source;
    pair<Vertex*, Vertex_str> *sourcePtr = NULL;
    for(it = avaibleVertex.begin(); it != avaibleVertex.end(); ++it)
    {
        if(*(it -> first) == *sourceFun) //get our
        {
            source = *it;
            sourcePtr = &(*it);
            break;
        }
    }
    for(it = avaibleVertex.begin(); it != avaibleVertex.end(); ++it)
    {
        if(*(it -> first) == *destFun) //get our
        {
            dest = *it;
            break;
        }
    }
    if(it != avaibleVertex.end() && !(dest.second.visited))   //already calculated
    {   //calculate
        if(dest.second.value > source.second.value + DISTANCE_BETWEEN_VERTECES) //check present distance
        {
            dest.second.value = source.second.value + DISTANCE_BETWEEN_VERTECES;
            dest.second.before = sourcePtr;
        }
    }
    else
    {   //add new vertex to availible
        if(!(dest.second.visited))
            avaibleVertex.push_back(
                    make_pair(destFun, Vertex_str(source.second.value + DISTANCE_BETWEEN_VERTECES, false, sourcePtr)));
    }
}

pair<Vertex*, Dijkstra::Vertex_str> Dijkstra::selectLeastVertix(list<pair<Vertex*, Vertex_str> > &avaibleVertex)
{
    list<pair<Vertex*, Vertex_str>>::iterator it = avaibleVertex.begin();
    list<pair<Vertex*, Vertex_str>>::iterator leastIt = avaibleVertex.begin();
    for(it, leastIt = avaibleVertex.begin(); it != avaibleVertex.end(); ++it)
    {
        if(leastIt -> second.visited) //we've started from same position
            leastIt = it;
        if(it -> second.visited) //alredy visited
            continue;
         int a = it->second.value, b = leastIt->second.value;
        if(it -> second.value <= leastIt -> second.value) //if present it is least as leasIt
            leastIt = it;
    }
    return *leastIt;
}
