#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <tuple>
 

int main()
{
    auto hist = [](int nbins, double min, double max) {
        std::vector<double> edges(nbins + 1);
        std::vector<int>    bins(nbins + 2);
        std::generate(edges.begin(), edges.end(), [nbins, min, max, n = 0]() mutable { return min + (max - min)/nbins*n++; });
        return std::make_tuple(edges, bins);
    };

    std::vector<double> data{1.2, 3.4, 5.6, 7.8, 9.0};
    std::vector<double> edges;
    std::vector<int>    bins;

    std::tie(edges, bins) = hist(20, 1, 10);

    auto to_bins = [edges, &bins](double& v) {
        auto offset = std::lower_bound(edges.begin(), edges.end(), v) - edges.begin();
        (*(bins.begin() + offset))++;
    };

    std::for_each(data.begin(), data.end(), to_bins);


    std::cout << "data:  ";
    std::copy(data.begin(), data.end(), std::ostream_iterator<double>(std::cout, " "));
    std::cout << '\n';

    std::cout << "edges: ";
    std::copy(edges.begin(), edges.end(), std::ostream_iterator<double>(std::cout, " "));
    std::cout << '\n';

    std::cout << "bins:  ";
    std::copy(bins.begin(), bins.end(), std::ostream_iterator<double>(std::cout, " "));
    std::cout << '\n';
}
