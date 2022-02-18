; Auto-generated. Do not edit!


(cl:in-package arduino_arm_control-msg)


;//! \htmlinclude jointCmd.msg.html

(cl:defclass <jointCmd> (roslisp-msg-protocol:ros-message)
  ((vel
    :reader vel
    :initarg :vel
    :type (cl:vector cl:float)
   :initform (cl:make-array 3 :element-type 'cl:float :initial-element 0.0))
   (angle
    :reader angle
    :initarg :angle
    :type (cl:vector cl:float)
   :initform (cl:make-array 3 :element-type 'cl:float :initial-element 0.0))
   (msg_ctr
    :reader msg_ctr
    :initarg :msg_ctr
    :type cl:integer
    :initform 0))
)

(cl:defclass jointCmd (<jointCmd>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <jointCmd>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'jointCmd)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name arduino_arm_control-msg:<jointCmd> is deprecated: use arduino_arm_control-msg:jointCmd instead.")))

(cl:ensure-generic-function 'vel-val :lambda-list '(m))
(cl:defmethod vel-val ((m <jointCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader arduino_arm_control-msg:vel-val is deprecated.  Use arduino_arm_control-msg:vel instead.")
  (vel m))

(cl:ensure-generic-function 'angle-val :lambda-list '(m))
(cl:defmethod angle-val ((m <jointCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader arduino_arm_control-msg:angle-val is deprecated.  Use arduino_arm_control-msg:angle instead.")
  (angle m))

(cl:ensure-generic-function 'msg_ctr-val :lambda-list '(m))
(cl:defmethod msg_ctr-val ((m <jointCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader arduino_arm_control-msg:msg_ctr-val is deprecated.  Use arduino_arm_control-msg:msg_ctr instead.")
  (msg_ctr m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <jointCmd>) ostream)
  "Serializes a message object of type '<jointCmd>"
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'vel))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'angle))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'msg_ctr)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'msg_ctr)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'msg_ctr)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'msg_ctr)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <jointCmd>) istream)
  "Deserializes a message object of type '<jointCmd>"
  (cl:setf (cl:slot-value msg 'vel) (cl:make-array 3))
  (cl:let ((vals (cl:slot-value msg 'vel)))
    (cl:dotimes (i 3)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits)))))
  (cl:setf (cl:slot-value msg 'angle) (cl:make-array 3))
  (cl:let ((vals (cl:slot-value msg 'angle)))
    (cl:dotimes (i 3)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits)))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'msg_ctr)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'msg_ctr)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'msg_ctr)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'msg_ctr)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<jointCmd>)))
  "Returns string type for a message object of type '<jointCmd>"
  "arduino_arm_control/jointCmd")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'jointCmd)))
  "Returns string type for a message object of type 'jointCmd"
  "arduino_arm_control/jointCmd")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<jointCmd>)))
  "Returns md5sum for a message object of type '<jointCmd>"
  "f9e54d2ce9916138a4992d6300c80c4c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'jointCmd)))
  "Returns md5sum for a message object of type 'jointCmd"
  "f9e54d2ce9916138a4992d6300c80c4c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<jointCmd>)))
  "Returns full string definition for message of type '<jointCmd>"
  (cl:format cl:nil "float32[3] vel #deg/s~%float32[3] angle #deg~%uint32 msg_ctr # count sent msgs to detected missed messages~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'jointCmd)))
  "Returns full string definition for message of type 'jointCmd"
  (cl:format cl:nil "float32[3] vel #deg/s~%float32[3] angle #deg~%uint32 msg_ctr # count sent msgs to detected missed messages~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <jointCmd>))
  (cl:+ 0
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'vel) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'angle) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <jointCmd>))
  "Converts a ROS message object to a list"
  (cl:list 'jointCmd
    (cl:cons ':vel (vel msg))
    (cl:cons ':angle (angle msg))
    (cl:cons ':msg_ctr (msg_ctr msg))
))
