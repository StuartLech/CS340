#include <iostream>
#include <fstream>
#include <ctime>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <cfloat>
#include <queue>

#include "Graph.h"
#include <iomanip>

using namespace std;

struct TourResult
{
    vector<int> tour;
    double distance;
};

void printTourResult(const TourResult &result, const string &algorithmName)
{
    cout << algorithmName << " Algorithm:\n";
    cout << "Tour: ";
    for (int city : result.tour)
    {
        cout << city + 1 << " ";
    }
    cout << "\nDistance: " << fixed << setprecision(2) << result.distance << "\n\n";
}

double calculateDistance(Node &node1, Node &node2)
{
    return sqrt(pow(node1.x - node2.x, 2) + pow(node1.y - node2.y, 2));
}

double calculateTotalDistance(std::priority_queue<int> tour, std::vector<Node> &nodes)
{
    double totalDistance = 0.0;
    int prevCity = tour.top();
    tour.pop();

    while (!tour.empty())
    {
        int currentCity = tour.top();
        tour.pop();
        totalDistance += calculateDistance(nodes[prevCity], nodes[currentCity]);
        prevCity = currentCity;
    }

    cout << endl;

    totalDistance += calculateDistance(nodes[prevCity], nodes[tour.top()]);

    return totalDistance;
}
TourResult bruteForce(Graph &graph, std::vector<Node> &nodes)
{
    std::priority_queue<int> tour;

    for (const auto &node : graph.graphNodes.nodes)
    {
        tour.push(node.id);
    }

    double minDistance = DBL_MAX;
    std::vector<int> minTour(tour.size());

    std::vector<int> tourVector;
    while (!tour.empty())
    {
        tourVector.push_back(tour.top());
        tour.pop();
    }

    do
    {
        double currentDistance = calculateTotalDistance(std::priority_queue<int>(tourVector.begin(), tourVector.end()), nodes);
        if (currentDistance < minDistance)
        {
            minDistance = currentDistance;
            minTour = tourVector;
        }
    } while (std::next_permutation(tourVector.begin(), tourVector.end()));

    TourResult result;
    result.tour = minTour;
    result.distance = minDistance;
    return result;
}

TourResult approximationAlgorithm(Graph &graph, std::vector<Node> &nodes)
{
    graph.generateMST();

    std::priority_queue<int> tour;
    for (const auto &node : graph.graphNodes.nodes)
    {
        tour.push(node.id);
    }

    TourResult result;
    result.tour.reserve(tour.size());
    double totalDistance = calculateTotalDistance(tour, nodes);

    // Store the tour for printing
    while (!tour.empty())
    {
        result.tour.push_back(tour.top());
        tour.pop();
    }

    result.distance = totalDistance;
    return result;
}

std::vector<std::vector<std::pair<double, double>>> readCoordinatesArray(const std::string &filename)
{
    std::ifstream file(filename);
    std::vector<std::vector<std::pair<double, double>>> coordinatesArray;

    if (!file)
    {
        std::cerr << "Failed to open coordinates file: " << filename << std::endl;
        return coordinatesArray;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::vector<std::pair<double, double>> nodeCoordinates;
        std::istringstream ss(line);
        double x, y;
        char comma;

        // Read the first pair of coordinates for the node
        ss >> x >> comma >> y;
        nodeCoordinates.push_back({x, y});

        // Read the remaining pairs for each graph
        for (int i = 1; i < 10; ++i)
        {
            ss >> comma >> x >> comma >> y;
            nodeCoordinates.push_back({x, y});
        }

        coordinatesArray.push_back(nodeCoordinates);
    }

    return coordinatesArray;
}

int main()
{
    clock_t start, end, startA, endA;

    std::string coordinatesFilename = "coordinates.csv";
    std::vector<std::vector<std::pair<double, double>>> coordinatesArray = readCoordinatesArray(coordinatesFilename);

    for (int graphNum = 1; graphNum <= 10; ++graphNum)
    {
        std::string graphFileName = "graph" + std::to_string(graphNum) + ".txt";
        std::ifstream graphFile(graphFileName);
        PriorityQueue queue;
        std::string line;

        if (!graphFile)
        {
            std::cerr << "Failed to open graph file: " << graphFileName << std::endl;
            return -1;
        }

        int count = 0;

        while (getline(graphFile, line))
        {
            pair<double, double> coord = coordinatesArray[count][graphNum - 1];

            Node node(line);
            node.x = coord.first;
            node.y = coord.second;
            queue.nodes.push_back(node);

            count++;
        }

        Graph graph(queue, 0);

        // Brute Force
        start = clock();
        TourResult bruteForceResult = bruteForce(graph, queue.nodes);
        end = clock();
        printTourResult(bruteForceResult, "Brute Force");
        cout << "Graph " << graphNum << " Running Time (Brute Force): "
             << fixed << setprecision(7) << (double)(end - start) / CLOCKS_PER_SEC << " seconds\n";

        // MST-based Approximation
        start = clock();
        TourResult approximationResult = approximationAlgorithm(graph, queue.nodes);
        end = clock();
        printTourResult(approximationResult, "MST-based Approximation");
        cout << "Graph " << graphNum << " Running Time (Approximation): "
             << fixed << setprecision(7) << (double)(end - start) / CLOCKS_PER_SEC << " seconds\n\n";
    }

    return 0;
}