/*
 * assignment1.hpp
 *
 *  Created on: May 10, 2017
 *      Author: Joe
 */

#ifndef ASSIGNMENT1_HPP_
#define ASSIGNMENT1_HPP_

#include <fstream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <map>
#include <assert.h>
#include <iostream>
#include "profile.hpp"

namespace assignment1
{
    namespace scheduling_problem
    {
        typedef std::tuple<int, int> job;	// job is a tuple of (weight, length)

        /* Compute score for each job in a vector as a function of job weight - job length */
        std::vector<std::tuple<int, job>> computeScoreDiff(const std::vector<job>& jobs)
        {
            std::vector<std::tuple<int, job>> scores;	// we'll assign score for each job

            for (auto job : jobs)
            {
                int score = std::get<0>(job) - std::get<1>(job);
                scores.push_back(std::make_tuple(score, job));
            }

            return scores;
        }

        /* Compute score for each job in a vector as a function of job weight / job length */
        std::vector<std::tuple<double, job>> computeScoreRatio(const std::vector<job>& jobs)
        {
            std::vector<std::tuple<double, job>> scores;	// we'll assign score for each job

            for (auto job : jobs)
            {
                double score = (double)std::get<0>(job) / std::get<1>(job);	// wj / lj
                scores.push_back(std::make_tuple(score, job));
            }

            return scores;
        }

        long long schedule_by_difference(const std::vector<job>& jobs)
        {
            auto scores = computeScoreDiff(jobs);
            // schedule jobs by decreasing value of scores
            std::sort(scores.begin(), scores.end(), [](std::tuple<int, job> a, std::tuple<int, job> b)
            {
                return a > b;
            });

            long long weighted_sum = 0;
            int total_length = 0;

            for (auto sorted_jobs : scores)	// we get the job
            {
                auto job = std::get<1>(sorted_jobs);
                total_length += std::get<1>(job);
                weighted_sum += std::get<0>(job) * total_length;	// wj*cj
            }

            return weighted_sum;
        }

        long long schedule_by_ratio(const std::vector<job>& jobs)
        {
            auto scores = computeScoreRatio(jobs);
            // schedule jobs by decreasing value of scores
            std::sort(scores.begin(), scores.end(), [](std::tuple<double, job> a, std::tuple<double, job> b)
            {
                return a > b;
            });

            long long weighted_sum = 0;
            int total_length = 0;

            for (auto sorted_jobs : scores)	// we get the job
            {
                auto job = std::get<1>(sorted_jobs);
                total_length += std::get<1>(job);
                weighted_sum += std::get<0>(job) * total_length;	// wj*cj
            }

            return weighted_sum;
        }

        void run_algorithm(const std::string& inputFile)
        {
            std::vector<job> jobs;
            std::ifstream file(inputFile, std::ios::in);

            if (file.is_open())
            {
                int n;
                int job_weight, job_length;

                file >> n;
                while (file >> job_weight >> job_length)
                {
                    std::tuple<int, int> job = std::make_tuple(job_weight, job_length);

                    jobs.push_back(job);
                }
                file.close();

                // Schedule by difference total weighted sum
                long long schedule_by_diff_sum = schedule_by_difference(jobs);
                std::cout << "Schedule by difference total weighted sum: " << schedule_by_diff_sum << std::endl;

                assert(schedule_by_diff_sum == 69119377652);

                // Schedule by ratio total weighted sum
                long long schedule_by_ratio_sum = schedule_by_ratio(jobs);
                std::cout << "Schedule by ratio total weighted sum: " << schedule_by_ratio_sum << std::endl;

                assert(schedule_by_ratio_sum == 67311454237);
            }
        }
    } // namespace

    namespace prims_algorithm
    {
        typedef std::tuple<int, int, int> Edge;	// edge has: source vertex, destination vertex and edge cost
        typedef std::map<int, std::vector<Edge>> Graph;		// source vertex connected to destination vertex vector (name, edge_cost)

        long long prims_algorithm(Graph& g)
        {
            long long result = 0;
            std::vector<int> X = { 1 };		// vertices spanned by tree T so far (initialize X with first vertex in first edge)
            std::vector<Edge> T;			// T is initially empty (tree_so_far)

            while (X.size() != g.size())
            {
                // let's go over all vertices in X so far and find adjancent min cost nodes
                Edge min_cost_edge;
                int min = 9999999;
                for (int u : X)	// always need to find the cheapest edge from whole set of adjacent vertices to set X
                {
                    // search min cost edge
                    for (auto edge : g[u])
                    {
                        if (std::find(X.begin(), X.end(), std::get<1>(edge)) == X.end()) // if target vertex is not in X
                        {
                            if (std::get<2>(edge) < min)
                            {
                                min_cost_edge = edge;
                                min = std::get<2>(edge);
                            }
                        }
                    }
                }
                // finally add the cheapest node overall (going out from X) and add destination node to X
                T.push_back(min_cost_edge);
                X.push_back(std::get<1>(min_cost_edge));	// add destination vertex to X
            }

            for (auto e : T)
            {
                result += std::get<2>(e);
            }

            return result;
        }

        bool test1()
        {
            // test case 1
            Graph test_g;
            test_g[1] = std::vector<Edge>
            {std::make_tuple(1, 2, 5),
            std::make_tuple(1, 3, 1),
            std::make_tuple(1, 4, 2)
            };
            test_g[2] = std::vector<Edge>
            {std::make_tuple(2, 1, 5),
            std::make_tuple(2, 4, 4)
            };
            test_g[3] = std::vector<Edge>
            {std::make_tuple(3, 1, 1),
            std::make_tuple(3, 4, 3)
            };
            test_g[4] = std::vector<Edge>
            {std::make_tuple(4, 1, 2),
            std::make_tuple(4, 2, 4),
            std::make_tuple(4, 3, 3)
            };

            assert(prims_algorithm(test_g) == 7);

            return true;
        }

        void run_algorithm(const std::string& inputFile)
        {
            std::vector<Edge> edges;
            Graph g;

            std::ifstream file(inputFile, std::ios::in);

            if (file.is_open())
            {
                PROFILE("Read file for Prim's algo");
                int num_nodes, num_edges;
                file >> num_nodes >> num_edges;

                int snode, dnode, cost;
                while (file >> snode >> dnode >> cost)
                {
                    Edge e = std::make_tuple(snode, dnode, cost);
                    edges.push_back(e);

                    g[snode].push_back(std::make_tuple(snode, dnode, cost));
                    g[dnode].push_back(std::make_tuple(dnode, snode, cost));

                }
                file.close();
                PROFILE_STOP();

                // Compute Prim's Minimum Spanning Tree
                PROFILE("Prim's algorithm");
                long long total_cost = prims_algorithm(g);
                PROFILE_STOP();
                std::cout << "Total cost of Prim's MST is: " << total_cost << std::endl;

                assert(total_cost == -3612829);
            }
        }
    } // namespace
} // namespace



#endif /* ASSIGNMENT1_HPP_ */
