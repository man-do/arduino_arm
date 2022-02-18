;; Auto-generated. Do not edit!


(when (boundp 'arduino_arm_control::jointCmd)
  (if (not (find-package "ARDUINO_ARM_CONTROL"))
    (make-package "ARDUINO_ARM_CONTROL"))
  (shadow 'jointCmd (find-package "ARDUINO_ARM_CONTROL")))
(unless (find-package "ARDUINO_ARM_CONTROL::JOINTCMD")
  (make-package "ARDUINO_ARM_CONTROL::JOINTCMD"))

(in-package "ROS")
;;//! \htmlinclude jointCmd.msg.html


(defclass arduino_arm_control::jointCmd
  :super ros::object
  :slots (_vel _angle _msg_ctr ))

(defmethod arduino_arm_control::jointCmd
  (:init
   (&key
    ((:vel __vel) (make-array 3 :initial-element 0.0 :element-type :float))
    ((:angle __angle) (make-array 3 :initial-element 0.0 :element-type :float))
    ((:msg_ctr __msg_ctr) 0)
    )
   (send-super :init)
   (setq _vel __vel)
   (setq _angle __angle)
   (setq _msg_ctr (round __msg_ctr))
   self)
  (:vel
   (&optional __vel)
   (if __vel (setq _vel __vel)) _vel)
  (:angle
   (&optional __angle)
   (if __angle (setq _angle __angle)) _angle)
  (:msg_ctr
   (&optional __msg_ctr)
   (if __msg_ctr (setq _msg_ctr __msg_ctr)) _msg_ctr)
  (:serialization-length
   ()
   (+
    ;; float32[3] _vel
    (* 4    3)
    ;; float32[3] _angle
    (* 4    3)
    ;; uint32 _msg_ctr
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32[3] _vel
     (dotimes (i 3)
       (sys::poke (elt _vel i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; float32[3] _angle
     (dotimes (i 3)
       (sys::poke (elt _angle i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; uint32 _msg_ctr
       (write-long _msg_ctr s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32[3] _vel
   (dotimes (i (length _vel))
     (setf (elt _vel i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     )
   ;; float32[3] _angle
   (dotimes (i (length _angle))
     (setf (elt _angle i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     )
   ;; uint32 _msg_ctr
     (setq _msg_ctr (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get arduino_arm_control::jointCmd :md5sum-) "f9e54d2ce9916138a4992d6300c80c4c")
(setf (get arduino_arm_control::jointCmd :datatype-) "arduino_arm_control/jointCmd")
(setf (get arduino_arm_control::jointCmd :definition-)
      "float32[3] vel #deg/s
float32[3] angle #deg
uint32 msg_ctr # count sent msgs to detected missed messages
")



(provide :arduino_arm_control/jointCmd "f9e54d2ce9916138a4992d6300c80c4c")


