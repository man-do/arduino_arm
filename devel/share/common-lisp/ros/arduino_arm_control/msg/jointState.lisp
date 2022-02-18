; Auto-generated. Do not edit!


(cl:in-package arduino_arm_control-msg)


;//! \htmlinclude jointState.msg.html

(cl:defclass <jointState> (roslisp-msg-protocol:ros-message)
  ((angle
    :reader angle
    :initarg :angle
    :type (cl:vector cl:float)
   :initform (cl:make-array 3 :element-type 'cl:float :initial-element 0.0))
   (vel
    :reader vel
    :initarg :vel
    :type (cl:vector cl:float)
   :initform (cl:make-array 3 :element-type 'cl:float :initial-element 0.0)))
)

(cl:defclass jointState (<jointState>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <jointState>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'jointState)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name arduino_arm_control-msg:<jointState> is deprecated: use arduino_arm_control-msg:jointState instead.")))

(cl:ensure-generic-function 'angle-val :lambda-list '(m))
(cl:defmethod angle-val ((m <jointState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader arduino_arm_control-msg:angle-val is deprecated.  Use arduino_arm_control-msg:angle instead.")
  (angle m))

(cl:ensure-generic-function 'vel-val :lambda-list '(m))
(cl:defmethod vel-val ((m <jointState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader arduino_arm_control-msg:vel-val is deprecated.  Use arduino_arm_control-msg:vel instead.")
  (vel m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <jointState>) ostream)
  "Serializes a message object of type '<jointState>"
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'angle))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'vel))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <jointState>) istream)
  "Deserializes a message object of type '<jointState>"
  (cl:setf (cl:slot-value msg 'angle) (cl:make-array 3))
  (cl:let ((vals (cl:slot-value msg 'angle)))
    (cl:dotimes (i 3)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits)))))
  (cl:setf (cl:slot-value msg 'vel) (cl:make-array 3))
  (cl:let ((vals (cl:slot-value msg 'vel)))
    (cl:dotimes (i 3)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<jointState>)))
  "Returns string type for a message object of type '<jointState>"
  "arduino_arm_control/jointState")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'jointState)))
  "Returns string type for a message object of type 'jointState"
  "arduino_arm_control/jointState")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<jointState>)))
  "Returns md5sum for a message object of type '<jointState>"
  "83437f1ff145bcfd3c05b464bdbb43d7")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'jointState)))
  "Returns md5sum for a message object of type 'jointState"
  "83437f1ff145bcfd3c05b464bdbb43d7")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<jointState>)))
  "Returns full string definition for message of type '<jointState>"
  (cl:format cl:nil "#Header header ~%float32[3] angle # degrees~%float32[3] vel # deg/s~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'jointState)))
  "Returns full string definition for message of type 'jointState"
  (cl:format cl:nil "#Header header ~%float32[3] angle # degrees~%float32[3] vel # deg/s~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <jointState>))
  (cl:+ 0
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'angle) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'vel) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <jointState>))
  "Converts a ROS message object to a list"
  (cl:list 'jointState
    (cl:cons ':angle (angle msg))
    (cl:cons ':vel (vel msg))
))
