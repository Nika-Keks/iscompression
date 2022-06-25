#pragma once
#include <cmath>
#include <functional>
#include <numeric>

namespace isc
{
    template <typename elemT>
    class WienerFilter
    {
    public:

        WienerFilter(size_t winSize);

        bool proc(elemT* signal, size_t sigSize) const;

    private:

        typedef std::function<double(double, size_t)> prefilter_t;

        std::vector<double> winCorrelate(elemT const* signal, size_t sigSize, prefilter_t const& prefilter) const;


        size_t m_winSize;
    };

    template < typename elemT>
    WienerFilter<elemT>::WienerFilter(size_t winSize) : m_winSize(winSize)
    {}

    template <typename elemT>
    bool WienerFilter<elemT>::proc(elemT* signal, size_t sigSize) const
    {
        if (signal == nullptr)
            return false;

        auto localMeans = winCorrelate(signal, sigSize, [](double x, size_t){return x;});
        auto localSTDs = winCorrelate(signal, sigSize, [&localMeans](double x, size_t i){
            return pow(x-localMeans[i], 2);
        });
        double meanSTD = std::accumulate(localSTDs.begin(), localSTDs.end(), 0.) / localSTDs.size();

        for (size_t i = 0; i < sigSize; i++){
            if (localSTDs[i] >= meanSTD){
                double stdRate = meanSTD / localSTDs[i];
                signal[i] = std::llround(stdRate * localMeans[i] + (1 - stdRate) * signal[i]);
            }
            else
                signal[i] = std::round(localMeans[i]);
        }

        return true;
    }

    template <typename elemT>
    std::vector<double> WienerFilter<elemT>::winCorrelate(elemT const* signal, size_t sigSize, WienerFilter<elemT>::prefilter_t const& prefilter) const
    {
        std::vector<double> result(sigSize);
        double currentVal = 0.;
        
        for (size_t i = 0; i < m_winSize / 2; i++)
            currentVal += prefilter(signal[i], i);

        for (size_t i = 0; i < sigSize; i++){
            
            if (i > m_winSize / 2)
                currentVal -= prefilter(signal[i - m_winSize / 2 - 1], i - m_winSize / 2 - 1);
            if (i + m_winSize / 2 < sigSize)
                currentVal += prefilter(signal[i + m_winSize / 2], i + m_winSize / 2);

            result[i] = currentVal / m_winSize;
        }
        
        return result;
    }

} // namespace isc
