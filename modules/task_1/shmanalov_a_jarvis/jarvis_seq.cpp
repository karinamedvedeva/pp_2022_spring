// Copyright 2022 Shmanalov Alexander
#include <random>
#include "../../modules/task_1/shmanalov_a_jarvis/jarvis_seq.h"

std::vector<Point> getRandomCombinationPoints(int size) {
    if (size <= 0) {
        throw -1;
    }
    std::random_device random;
    std::mt19937 generate(random());
    std::vector<Point> points(size);
    for (int i = 0; i < size; i++) {
        int x = generate() % 800;
        int y = generate() % 800;
        points[i] = Point(x, y);
    }
    return points;
}

Point searchStartPoint(const std::vector<Point>& points) {
    Point startPoint = points[0];
    for (size_t i = 1; i < points.size(); i++) {
        if (points[i] < startPoint)
            startPoint = points[i];
    }
    return startPoint;
}

int getOrientation(const Point& cur, const Point& next, const Point& tmp) {
    return (tmp.first - cur.first) * (next.second - cur.second) -
        (tmp.second - cur.second) * (next.first - cur.first);
}

bool checkDistance(const Point& cur, const Point& next, const Point& tmp) {
    int distNextCur = (next.first - cur.first) * (next.first - cur.first) +
        (next.second - cur.second) * (next.second - cur.second);
    int distTmpCur = (tmp.first - cur.first) * (tmp.first - cur.first) +
        (tmp.second - cur.second) * (tmp.second - cur.second);
    if (distNextCur < distTmpCur) {
        return true;
    }
    return false;
}

std::vector<Point> sequentinalJarvis(const std::vector<Point>& points) {
    size_t numberOfPoints = points.size();
    if (numberOfPoints == 0) {
        throw -1;
    }
    if (numberOfPoints < 2) {
        return points;
    }
    Point start = searchStartPoint(points);
    std::vector<Point> result;
    result.push_back(start);
    Point currentPoint = start;
    Point nextPoint;
    do {
        if (currentPoint == points[0]) {
            nextPoint = points[1];
        } else {
            nextPoint = points[0];
        }
        for (size_t i = 0; i < numberOfPoints; i++) {
            int direction = getOrientation(currentPoint, nextPoint, points[i]);
            if (direction > 0) {
                nextPoint = points[i];
            } else if (direction == 0) {
                if (checkDistance(currentPoint, nextPoint, points[i])) {
                    nextPoint = points[i];
                }
            }
        }
        currentPoint = nextPoint;
        result.push_back(nextPoint);
    } while (currentPoint != start);
    result.pop_back();
    return result;
}
