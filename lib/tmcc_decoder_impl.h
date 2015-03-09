/* -*- c++ -*- */
/* 
 * Copyright 2015 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_ISDBT_TMCC_DECODER_IMPL_H
#define INCLUDED_ISDBT_TMCC_DECODER_IMPL_H

#include <isdbt/tmcc_decoder.h>
#include <stdio.h>

namespace gr {
    namespace isdbt {

        class tmcc_decoder_impl : public tmcc_decoder
        {
            private:
                /*ATTRIBUTES*/

                static const int tmcc_carriers_size_2k;
                static const int tmcc_carriers_2k[];
                static const int tmcc_carriers_size_4k;
                static const int tmcc_carriers_4k[];
                static const int tmcc_carriers_size_8k;
                static const int tmcc_carriers_8k[];

                int tmcc_carriers_size;
                const int * tmcc_carriers;

                static const int d_ac_carriers_2k[];
                static const int ac_carriers_size_2k;
                static const int d_ac_carriers_4k[];
                static const int ac_carriers_size_4k;
                static const int d_ac_carriers_8k[];
                static const int ac_carriers_size_8k;

                int ac_carriers_size;
                const int * d_ac_carriers;

                static const int d_data_carriers_per_segment_2k;
                static const int d_data_carriers_per_segment_4k;
                static const int d_data_carriers_per_segment_8k;
                static const int d_carriers_per_segment_2k;

                // Number of data carriers per segment
                int d_data_carriers_per_segment;

                static const int sp_per_segment_2k;
                static const int sp_per_segment_4k;
                static const int sp_per_segment_8k;

                int sp_per_segment;

                // Number of active carriers
                int active_carriers;

                static const int d_segments_positions[];

                // Number of segments
                static const int d_total_segments;

                // Number of segments
                static const int d_symbols_per_frame;

                // Number of carriers per segment
                int d_carriers_per_segment;

                static const int d_tmcc_sync_size;

                // Keeps the rcv TMCC data, is a FIFO
                std::deque<char> d_rcv_tmcc_data;
                // Keeps the TMCC sync sequence
                std::deque<char> d_tmcc_sync_evenv;
                std::deque<char> d_tmcc_sync_oddv;

                static const int d_tmcc_sync_even[];
                static const int d_tmcc_sync_odd[];

                // Keep TMCC carriers values from previous symbol
                gr_complex * d_prev_tmcc_symbol;

                // See if the symbol index is known
                int d_symbol_index_known;

                // indicates whether the last symbol was a frame end
                int d_frame_end;

                // Symbol Index
                int d_symbol_index;

                int number_symbol;

                // how many symbols ago we saw a complete tmcc
                int d_since_last_tmcc;


                /*METHODS*/

                // TMCC data processing metod
                int process_tmcc_data(const gr_complex * in);

                // ...
                void carriers_parameters(int payload);


            public:
                tmcc_decoder_impl(int mode);
                ~tmcc_decoder_impl();

                // Where all the action really happens
                void forecast (int noutput_items, gr_vector_int &ninput_items_required);

                int general_work(int noutput_items,
                        gr_vector_int &ninput_items,
                        gr_vector_const_void_star &input_items,
                        gr_vector_void_star &output_items);
        };

    } // namespace isdbt
} // namespace gr

#endif /* INCLUDED_ISDBT_TMCC_DECODER_IMPL_H */

