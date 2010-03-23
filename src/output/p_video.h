/*
   mkvmerge -- utility for splicing together matroska files
   from component media subtypes

   Distributed under the GPL
   see the file COPYING for details
   or visit http://www.gnu.org/copyleft/gpl.html

   class definition for the video output module

   Written by Moritz Bunkus <moritz@bunkus.org>.
*/

#ifndef __P_VIDEO_H
#define __P_VIDEO_H

#include "common/common_pch.h"

#include "merge/pr_generic.h"

#define VFT_IFRAME          -1
#define VFT_PFRAMEAUTOMATIC -2
#define VFT_NOBFRAME        -1

class video_packetizer_c: public generic_packetizer_c {
protected:
  double m_fps;
  int m_width, m_height, m_frames_output;
  int64_t m_ref_timecode, m_duration_shift;
  bool m_pass_through;

public:
  video_packetizer_c(generic_reader_c *p_reader, track_info_c &p_ti, const char *codec_id, double fps, int width, int height);

  virtual int process(packet_cptr packet);
  virtual void set_headers();

  virtual const char *get_format_name() {
    return "video";
  }
  virtual connection_result_e can_connect_to(generic_packetizer_c *src, std::string &error_message);

protected:
  virtual void check_fourcc();
};

#endif // __P_VIDEO_H
