#include "zkeyoperationconfig.h"
#include <QKeySequence>

#include "zkeyoperationmap.h"
#include "zstackoperator.h"

ZKeyOperationConfig::ZKeyOperationConfig()
{
}

void ZKeyOperationConfig::Configure(
    ZKeyOperationMap &map, ZKeyOperation::EGroup group)
{
  switch (group) {
  case ZKeyOperation::OG_SWC_TREE_NODE:
    ConfigureSwcNodeMap(map);
    break;
  case ZKeyOperation::OG_STACK:
    ConfigureStackMap(map);
    break;
  default:
    break;
  }
}

void ZKeyOperationConfig::ConfigureStackMap(ZKeyOperationMap &map)
{
  QMap<int, ZStackOperator::EOperation> &plainKeyMap = *(map.getPlainMap());

  plainKeyMap[Qt::Key_W] = ZStackOperator::OP_IMAGE_MOVE_UP;
  plainKeyMap[Qt::Key_A] = ZStackOperator::OP_IMAGE_MOVE_LEFT;
  plainKeyMap[Qt::Key_S] = ZStackOperator::OP_IMAGE_MOVE_DOWN;
  plainKeyMap[Qt::Key_D] = ZStackOperator::OP_IMAGE_MOVE_RIGHT;

  plainKeyMap[Qt::Key_Q] = ZStackOperator::OP_STACK_DEC_SLICE;
  plainKeyMap[Qt::Key_E] = ZStackOperator::OP_STACK_INC_SLICE;

  QMap<int, ZStackOperator::EOperation> &shiftKeyMap = *(map.getShiftMap());

  shiftKeyMap[Qt::Key_W] = ZStackOperator::OP_IMAGE_MOVE_UP_FAST;
  shiftKeyMap[Qt::Key_A] = ZStackOperator::OP_IMAGE_MOVE_LEFT_FAST;
  shiftKeyMap[Qt::Key_S] = ZStackOperator::OP_IMAGE_MOVE_DOWN_FAST;
  shiftKeyMap[Qt::Key_D] = ZStackOperator::OP_IMAGE_MOVE_RIGHT_FAST;

  shiftKeyMap[Qt::Key_Q] = ZStackOperator::OP_STACK_DEC_SLICE_FAST;
  shiftKeyMap[Qt::Key_E] = ZStackOperator::OP_STACK_INC_SLICE_FAST;
}

void ZKeyOperationConfig::ConfigureSwcNodeMap(ZKeyOperationMap &map)
{
  QMap<int, ZStackOperator::EOperation> &plainKeyMap = *(map.getPlainMap());

  plainKeyMap[Qt::Key_Backspace] = ZStackOperator::OP_SWC_DELETE_NODE;
  plainKeyMap[Qt::Key_Backspace] = ZStackOperator::OP_SWC_DELETE_NODE;
  plainKeyMap[Qt::Key_Backspace] = ZStackOperator::OP_SWC_DELETE_NODE;

  plainKeyMap[Qt::Key_W] = ZStackOperator::OP_SWC_MOVE_NODE_UP;
  plainKeyMap[Qt::Key_A] = ZStackOperator::OP_SWC_MOVE_NODE_LEFT;
  plainKeyMap[Qt::Key_S] = ZStackOperator::OP_SWC_MOVE_NODE_DOWN;
  plainKeyMap[Qt::Key_D] = ZStackOperator::OP_SWC_MOVE_NODE_RIGHT;
  plainKeyMap[Qt::Key_G] = ZStackOperator::OP_SWC_ENTER_ADD_NODE;

  plainKeyMap[Qt::Key_Q] = ZStackOperator::OP_SWC_DECREASE_NODE_SIZE;
  plainKeyMap[Qt::Key_E] = ZStackOperator::OP_SWC_INCREASE_NODE_SIZE;
  plainKeyMap[Qt::Key_C] = ZStackOperator::OP_SWC_CONNECT_NODE;
  plainKeyMap[Qt::Key_B] = ZStackOperator::OP_SWC_BREAK_NODE;
  plainKeyMap[Qt::Key_N] = ZStackOperator::OP_SWC_CONNECT_ISOLATE;
  plainKeyMap[Qt::Key_Z] = ZStackOperator::OP_SWC_ZOOM_TO_SELECTED_NODE;
  plainKeyMap[Qt::Key_I] = ZStackOperator::OP_SWC_INSERT_NODE;
  plainKeyMap[Qt::Key_F] = ZStackOperator::OP_SWC_LOCATE_FOCUS;
  plainKeyMap[Qt::Key_V] = ZStackOperator::OP_SWC_MOVE_NODE;
  plainKeyMap[Qt::Key_R] = ZStackOperator::OP_SWC_RESET_BRANCH_POINT;
  plainKeyMap[Qt::Key_Space] = ZStackOperator::OP_SWC_ENTER_EXTEND_NODE;

  QMap<int, ZStackOperator::EOperation> &shiftKeyMap = *(map.getShiftMap());

  shiftKeyMap[Qt::Key_W] = ZStackOperator::OP_SWC_MOVE_NODE_UP_FAST;
  shiftKeyMap[Qt::Key_A] = ZStackOperator::OP_SWC_MOVE_NODE_LEFT_FAST;
  shiftKeyMap[Qt::Key_S] = ZStackOperator::OP_SWC_MOVE_NODE_DOWN_FAST;
  shiftKeyMap[Qt::Key_D] = ZStackOperator::OP_SWC_MOVE_NODE_RIGHT_FAST;
  shiftKeyMap[Qt::Key_C] = ZStackOperator::OP_SWC_CONNECT_NODE_SMART;

  QMap<int, ZStackOperator::EOperation> &controlKeyMap = *(map.getControlMap());
  controlKeyMap[Qt::Key_A] = ZStackOperator::OP_SWC_SELECT_ALL_NODE;
}