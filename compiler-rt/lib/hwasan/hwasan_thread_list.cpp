#include "hwasan_thread_list.h"

namespace __hwasan {

static HwasanThreadList *hwasan_thread_list;

HwasanThreadList &hwasanThreadList() { return *hwasan_thread_list; }

void InitThreadList(uptr storage, uptr size) {
  CHECK_EQ(hwasan_thread_list, nullptr);

  static ALIGNED(alignof(
      HwasanThreadList)) char thread_list_placeholder[sizeof(HwasanThreadList)];
  hwasan_thread_list =
      new (thread_list_placeholder) HwasanThreadList(storage, size);
}

} // namespace __hwasan
